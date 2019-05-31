#include "toolkit.h"

void pr_stdio(const char *name, FILE *fp)  
{  
    printf("stream = %s,  ", name);  
    if (fp->_IO_file_flags & _IO_UNBUFFERED)  
        printf("unbuffered");  
    else if (fp->_IO_file_flags & _IO_LINE_BUF)  
        printf("line buffered");  
    else  
        printf("fully buffered");  
    printf(", buffer size = %ld\n", fp->_IO_buf_end - fp->_IO_buf_base);  
}  