#include "apue.h"
#include <time.h>

#define BUF_SIZE 64

void mydate();

int main(int argc, char *argv[])
{
    mydate();
    setenv("TZ", "UTC+8", 1);
    mydate();
    return 0;
}

void mydate()
{
    char buf[BUF_SIZE];

    time_t sec_since_epoch = time(NULL);
    struct tm tmstruct = *localtime(&sec_since_epoch);
    if (strftime(buf, BUF_SIZE, "%a %b %e %I:%M:%S %Z %Y", &tmstruct) == 0)
    {
        err_sys("buffer is too small");
    }
    printf("%s\n", buf);
}
