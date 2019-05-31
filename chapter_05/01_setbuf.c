#include "apue.h"
#include "toolkit.h"

int mysetbuf(FILE *restrict, char *restrict);

int main(int argc, char *argv[])
{
    // Print the buf type of the output stream.
    pr_stdio("stdout", stdout);
    // Turn off buffering for stdout.
    mysetbuf(stdout, NULL);
    // Print the buf type of the stream now.
    pr_stdio("stdout", stdout);
    return 0;
}

int mysetbuf(FILE *restrict stream, char *restrict buf)
{
    return setvbuf(stream, buf, (buf != NULL ? _IOFBF : _IONBF), BUFSIZ);
}
