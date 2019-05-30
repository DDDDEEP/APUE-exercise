#include "apue.h"
#include <fcntl.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source> <target>\n", argv[0]);
        return -1;
    }
    int source = open(argv[1], O_RDONLY);
    int target = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC);
    
    off_t curr;     // 当前复制中的数据区位置
    off_t hole_pos; // 下一个空洞区的位置
    
    hole_pos = lseek(source, 0, SEEK_HOLE);
    // 0 位置开始不是空洞区
    if (hole_pos > 0)
    {
        curr = 0;
        lseek(source, curr, SEEK_DATA);
    }
    // 0 位置开始是空洞区
    else
    {
        curr = lseek(source, 0, SEEK_DATA);
        hole_pos = lseek(source, curr, SEEK_HOLE);
        lseek(target, curr, SEEK_SET);
    }
    
    // 复制数据区，直至当前位置值到达空洞区
    // 此时找到下一个数据区和空洞区，继续复制
    int in_data = 1;
    char buf[BUF_SIZE];
    int to_copy;
    int data_left;
    while (curr < hole_pos)
    {
        if (in_data)
        {
            data_left = hole_pos - curr;
            if (data_left > BUF_SIZE)
            {
                to_copy = BUF_SIZE;
            }
            else {
                to_copy = data_left;
                in_data = 0;
            }
            read(source, &buf, to_copy);
            write(target, &buf, to_copy);
            curr += to_copy;
        }
        else
        {
            curr = lseek(source, curr, SEEK_DATA);
            hole_pos = lseek(source, curr, SEEK_HOLE);
            lseek(target, curr, SEEK_SET);
        }
    }
    
    return 0;
}