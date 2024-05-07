// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
#include "unp.h"

#define LINES 2000
#define LINE_SIZE 4096

char buf[LINE_SIZE];

int main()
{
    int fd;

    fd = open("2000.lines", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE);

    for (int i = 0; i < LINES; ++i)
    {
        memset(buf, 'a' + (i % 26), LINE_SIZE - 1);
        buf[LINE_SIZE - 1] = '\n';
        write(fd, buf, sizeof(buf));
    }

    return 0;
}