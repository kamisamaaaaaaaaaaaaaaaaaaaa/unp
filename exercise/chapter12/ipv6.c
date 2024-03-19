#include "unp.h"

int main(int argc, char *argv[])
{
    int listenfd;
    struct sockaddr_in6 serveraddr;

    if (argc != 2)
    {
        err_quit("usage: ./ipv4 ip");
    }

    listenfd = Socket(AF_INET6, SOCK_STREAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin6_family = AF_INET6;
    serveraddr.sin6_port = htons(9999);
    Inet_pton(AF_INET6, argv[1], &serveraddr.sin6_addr);

    int on = 1;
    Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    Bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr));

    Listen(listenfd, LISTENQ);

    pause();

    return 0;
}