#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    const char* dirname = "mydir";

    long pathmax = pathconf(".", _PC_PATH_MAX);
    printf("pathmax: %ld\n", pathmax);
    char path[pathmax];
    long curr_len;
    while ((curr_len = strlen(getcwd(path, pathmax))) < pathmax) {
        if (mkdir(dirname, DIR_MODE) < 0) {
            err_sys("mkdir failed");
        }
        chdir(dirname);
        printf("current absolute path length: %ld\n", curr_len);
    }
    return 0;
}