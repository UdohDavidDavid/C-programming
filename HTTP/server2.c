#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[]) {
	struct sockaddr_in {
		short sin_family;
		unsigned short sin_port;
		struct in_addr sin_addr;
		char sin_zero[8];
	};

	struct in_addr {
		unsigned long s_addr;
	};

	struct sockaddr_in my_addr;
	int sockfd;

	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0 ) {
		printf("Error while creating socket</span>");
		exit(1);
	}

	bzero(&my_addr, sizeof(my_addr));

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(5100);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ((bind(sockfd, (struct sockaddr *) &my_addr, sizeof(my_addr))) < 0) {
		printf("Error binding</span>n");
		exit(1);
	}

}
