#include "apue.h"

int main(int charc, char * argv[]) {
    
    pid_t pid;
    char buf[20];
    
    if ((pid = fork()) < 0)
    {
        err_sys("fork failed");
    }
    else if (pid == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        sprintf(buf, "ps %ld", (long int)pid);
        system(buf);
    }
    return 0;
}