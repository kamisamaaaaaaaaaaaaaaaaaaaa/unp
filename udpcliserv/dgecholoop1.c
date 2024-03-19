#include "unp.h"

static void recvfrom_int(int);
static int count;

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	socklen_t len;
	char mesg[MAXLINE];

	Signal(SIGINT, recvfrom_int);

	sleep(10);
	printf("get started!\n");

	for (;;)
	{
		len = clilen;
		Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

		count++;
		printf("%d\n", count);
	}
}

static void
recvfrom_int(int signo)
{
	printf("\nreceived %d datagrams\n", count);
	exit(0);
}
