#include "unp.h"
#define SCTP_MAXLINE 800
void sctpstr_cli_echoall(FILE *fp, int sock_fd, struct sockaddr *to, socklen_t tolen)
{
	struct sockaddr_in peeraddr;
	struct sctp_sndrcvinfo sri;
	char sendline[SCTP_MAXLINE], recvline[SCTP_MAXLINE];
	socklen_t len;
	int rd_sz, i, strsz;
	int msg_flags;

	bzero(sendline, sizeof(sendline));
	bzero(&sri, sizeof(sri));

	while (fgets(sendline, SCTP_MAXLINE - 9, fp) != NULL)
	{
		strsz = strlen(sendline);
		if (sendline[strsz - 1] == '\n')
		{
			sendline[strsz - 1] = '\0';
			strsz--;
		}
		for (i = 0; i < SERV_MAX_SCTP_STRM; i++)
		{
			snprintf(sendline + strsz, sizeof(sendline) - strsz,
					 ".msg.%d", i);
			Sctp_sendmsg(sock_fd, sendline, sizeof(sendline),
						 to, tolen,
						 0, 0,
						 i,
						 0, 0);
		}
		for (i = 0; i < SERV_MAX_SCTP_STRM; i++)
		{
			len = sizeof(peeraddr);
			rd_sz = Sctp_recvmsg(sock_fd, recvline, sizeof(recvline),
								 (SA *)&peeraddr, &len,
								 &sri, &msg_flags);
			printf("From str:%d seq:%d (assoc:0x%x):",
				   sri.sinfo_stream, sri.sinfo_ssn,
				   (unsigned int)sri.sinfo_assoc_id);
			printf("rd_sz is %d content is %.*s\n", rd_sz, rd_sz, recvline);
		}
	}
}

int main(int argc, char **argv)
{
	int sock_fd;
	struct sockaddr_in servaddr;
	struct sctp_event_subscribe evnts;
	int echo_to_all = 0;

	if (argc < 2)
		err_quit("Missing host argument - use '%s host [echo]'\n",
				 argv[0]);
	if (argc > 2)
	{
		printf("Echoing messages to all streams\n");
		echo_to_all = 1;
	}
	sock_fd = Socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	bzero(&evnts, sizeof(evnts));
	evnts.sctp_data_io_event = 1;
	Setsockopt(sock_fd, IPPROTO_SCTP, SCTP_EVENTS,
			   &evnts, sizeof(evnts));
	if (echo_to_all == 0)
		sctpstr_cli(stdin, sock_fd, (SA *)&servaddr, sizeof(servaddr));
	else
		sctpstr_cli_echoall(stdin, sock_fd, (SA *)&servaddr, sizeof(servaddr));
	Close(sock_fd);
	return (0);
}
