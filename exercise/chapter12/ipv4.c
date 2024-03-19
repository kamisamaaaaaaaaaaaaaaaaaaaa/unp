#include "unp.h"

int main(int argc, char *argv[])
{
    int listenfd;
    struct sockaddr_in serveraddr;

    if (argc != 2)
    {
        err_quit("usage: ./ipv4 ip");
    }

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
    Inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    int on = 1;
    Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    Bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr));

    Listen(listenfd, LISTENQ);

    pause();

    return 0;
}