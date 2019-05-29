#include "apue.h"

int dup2(int fd1, int fd2)
{
    // 描述符相同时，直接返回
    if (fd1 == fd2)
    {
        printf("same descriptor: %d\n", fd2);
        return fd2;
    }
    close(fd2);

    // 关闭 fd2 后，利用 dup 函数返回的新描述符一定是当前最小的可用描述符的性质
    // 不断复制 fd1，直到新的描述符与原来的 fd2 相等
    // 然后关闭其它新描述符，最后返回
    int fds[fd2];
    int fdi = 0;
    int descriptor = -1;
    while (descriptor != fd2)
    {
        if ((descriptor = dup(fd1)) < 0)
        {
            err_sys("dup(fd1) failed");
        }
        printf("new dup(fd1): %d\n", descriptor);
        fds[fdi] = descriptor;
        ++fdi;
    }

    for (int i = 0; i < fdi - 1; i++)
    {
        printf("close descriptor: %d\n", fds[i]);
        close(fds[i]);
    }
    printf("fd2 descriptor: %d\n", descriptor);
    return descriptor;
}

int main() {
    int fd1, fd2;
    printf("input fd1 and fd2:\n");
    scanf("%d %d", &fd1, &fd2);
    dup2(fd1, fd2);
    return 0;
}