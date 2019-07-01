
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAXLINE (1024 * 1024 -1)
typedef struct sockaddr SA;

ssize_t						/* Write "n" bytes to a file descriptor. */
writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = (const char *)vptr;
	nleft = n;
	while (nleft > 0) {
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
			//if (nwritten < 0 && errno == EINTR)
			//	nwritten = 0;		/* and call write() again */
			//else
				return(-1);			/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n);
}
/* end writen */

void
Writen(int fd, void *ptr, size_t nbytes)
{
	if (writen(fd, ptr, nbytes) != nbytes) {
		printf("writen error");
        exit(1);
    }
}

void parseUrl() {
}

string getHost(string url) {
    //url = "http://www.hao123.com/xxx/yyy/zzz.html";
    string host = "";
    int pos = url.find("://");
    if(pos == -1) {
        pos = 0;
    } else {
        pos += 3;
    }

    url = url.substr(pos);
    int pos2 = url.find_first_of("/");
    if(pos2 != -1) {
        host = url.substr(pos, pos2);
    } else {
        host = url;
    }
    return host;
}

string getFile(string url) {
    //url = "http://www.hao123.com/xxx/yyy/zzz.html";
    string file = "";
    int pos = url.find("://");
    if(pos == -1) {
        pos = 0;
    } else {
        pos += 3;
    }
    url = url.substr(pos);
    int pos2 = url.find_first_of("/");
    if(pos2 != -1) {
        file = url.substr(pos2 + 1);
    } else {
    }
    return file;
}

string getHtml(string url) {
	int sockfd, n;
	char recvline[MAXLINE + 1] = "";
    char sentline[MAXLINE + 1] = "";
	struct sockaddr_in	servaddr;
    struct hostent* servhost;

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket error");
        exit(1);
    }
    string host = getHost(url);
    string file = getFile(url);
    servhost = gethostbyname(host);


    strcat(buff, "GET ");
    strcat(buff, file);
    strcat(buff, " HTTP/1.1\r\n");

    strcat(buff, "Host: ");
    strcat(buff, host);
    strcat(buff, "\r\n");

    string accept = "Accept: */*\r\nAccept-Language: zh-cn\r\nAccept-Encoding: gzip, deflate\r\n";
    strcat(buff, accept);
    //不同的主机UserAgent不同
    string userAgent = "Mozilla/5.0 (X11; U; Linux i686; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.224 Safari/534.10";

    strcat(buff, "User-Agent: ");
    strcat(buff, userAgent);
    strcat(buff, "\r\n");

    strcat(buff, "Connection: Keep-Alive\r\n\r\n");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(80);
    servadd.sin_addr = (struct sockaddr_in*)servhost -> sin_addr;

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
		printf("connect error");
        exit(1);
    }

    Writen(sockfd, buff, strlen(buff));

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		counter_++;
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF) {
			printf("fputs error");
            exit(1);
        }
	}
	if (n < 0) {
		printf("read error");
        exit(1);
    }
}

int main(int argc, char **argv) {

	if (argc != 2) {
		printf("usage: a.out <url>");
        exit(1);
    }
    std::string page = getHtml(new std::string(argv[1]));
    std::cout << page << std::endl;
	exit(0);
}

