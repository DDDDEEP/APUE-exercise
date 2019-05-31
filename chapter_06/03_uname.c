#include "apue.h"
#include <sys/utsname.h>

int main(int argc, char *argv[])
{
    struct utsname u;
    if (uname(&u) < 0)
    {
        err_sys("uname error");
    }
    
    printf("sysname:  %s\n", u.sysname);
    printf("nodename: %s\n", u.nodename);
    printf("release:  %s\n", u.release);
    printf("version:  %s\n", u.version);
    printf("machine:  %s\n", u.machine);
    return 0;
}