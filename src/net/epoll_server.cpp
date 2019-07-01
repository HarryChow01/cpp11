
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include<arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <stdio.h>


const int kMaxEvents = 64;
char ip[] = "127.0.0.1";
const int kPort = 12345;
const int kBufferSize = 4 * 1024;

static int set_non_blocking(int fd) {
    int flags, ret;
    flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }

    flags |= O_NONBLOCK;
    ret = fcntl(fd, F_SETFL, flags);
    if (ret == -1) {
        perror("fcntl");
        return -1;
    }
    return 0;
}




int main(int argc, char *argv[]) {
    int listenfd, ret;
    int epollfd;
    struct epoll_event event;
    std::vector<epoll_event> events(kMaxEvents);

    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof serv_addr);
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(kPort);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    ret = set_non_blocking(listenfd);

    bind(listenfd, (sockaddr *)(&serv_addr), sizeof(serv_addr));
    ret = listen(listenfd, 10);
    if (ret == -1) {
        perror("listen");
        abort();
    }

    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create");
        abort();
    }

    event.data.fd = listenfd;
    event.events = EPOLLIN | EPOLLET;
    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &event);
    if (ret == -1) {
        perror("epoll_ctl");
        abort();
    }

    /* The event loop */
    while (true) {
        int readyNum = epoll_wait(epollfd, events.data(), kMaxEvents, -1);
        for (int i = 0; i < readyNum; i++) {
            if ((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                (!(events[i].events & EPOLLIN))) {
                /* An error has occured on this fd, or the socket is not
                   ready for reading (why were we notified then?) */
                perror("epoll error");
                close(events[i].data.fd);
                continue;
            } else if (listenfd == events[i].data.fd) {
                while (true) {
                    struct sockaddr client_addr;
                    socklen_t addr_len = sizeof client_addr;;
                    char buff[kBufferSize];

                    int clientfd = accept(listenfd, &client_addr, &addr_len);
                    if (clientfd == -1) {
                        if ((errno == EAGAIN) ||
                            (errno == EWOULDBLOCK)) {
                            /* We have processed all incoming
                               connections. */
                            break;
                        } else {
                            perror("accept");
                            break;
                        }
                    }
                    ret = set_non_blocking(clientfd);
                    if (ret == -1)
                        abort();

                    event.data.fd = clientfd;
                    event.events = EPOLLIN | EPOLLET;
                    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &event);
                    if (ret == -1) {
                        perror("epoll_ctl");
                        abort();
                    }
                }
            } else {
                /* We have data on the fd waiting to be read. Read and
                   display it. We must read whatever data is available
                   completely, as we are running in edge-triggered mode
                   and won't get a notification again for the same
                   data. */
                int clientfd = events[i].data.fd;
                int done = 0;
                while (true) {
                    char buf[kBufferSize];
                    ssize_t count = read(events[i].data.fd, buf, sizeof buf);
                    if (count == -1) {
                        /* If errno == EAGAIN, that means we have read all
                           data. So go back to the main loop. */
                        if (errno != EAGAIN) {
                            perror("read");
                            done = 1;
                        }
                        break;
                    } else if (count == 0) {
                        /* End of file. The remote has closed the
                           connection. */
                        done = 1;
                        break;
                    }
                    /* Write the buffer to standard output */
                    ret = write(clientfd, buf, count);
                    if (ret == -1) {
                        perror("write clientfd");
                        abort();
                    }
                }
                if (done) {
                    printf("Closed connection on descriptor %d\n", events[i].data.fd);
                    /* Closing the descriptor will make epoll remove it
                       from the set of descriptors which are monitored. */
                    close(events[i].data.fd);
                }
            } // end else
        } // end for
    } // end while

    close(listenfd);
    return 0;
}



