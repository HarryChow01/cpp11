#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include<arpa/inet.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int16_t kServerPort = 12345;
const uint32_t kBufferSize = 4 * 1024;
const uint32_t kMaxLine = 4 * 1024;


void str_cli(FILE *fp, int sockfd) {
	char sendline[kMaxLine];
	char recvline[kMaxLine];

	while (fgets(sendline, kMaxLine, fp) != nullptr) {
		write(sockfd, sendline, sizeof sendline);

		if (read(sockfd, recvline, kMaxLine) == 0) {
			perror("read from socket error");
			exit(1);
		}
		fputs(recvline, stdout);
	}
}

int main(int argc, char **argv) {
	int	sockfd;
	struct sockaddr_in servaddr;


	if (argc != 2) {
		perror("usage: tcpcli <IPaddress>");
		exit(0);
	}


	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0, sizeof servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(kServerPort);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	connect(sockfd, (sockaddr *) &servaddr, sizeof(servaddr));
	str_cli(stdin, sockfd);		/* do it all */

	return 0;
}
