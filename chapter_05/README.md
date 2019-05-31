## 5.1 用 setvbuf 实现 setbuf

## 5.2 在每次一行 I/O 复制文件的程序中，若将 MAXLINE 改为 4 后，当复制行超过最大值时会出现什么情况？

`fgets` 函数读入数据直至行结束或缓冲区满，且其会留出一个字节存放终止 null 字节

同样，`fputs` 只负责将缓冲区输出直到遇到一个 null 字节，其并不考虑缓冲区是否包含换行符

因此将 MAXLINE 设置得很小并不影响函数工作，只是会增加函数调用次数

## 5.3 printf 返回 0 代表什么？

没有输出任何字符，如 `printf("");`

## 5.4 下面代码在一些机器运行正确，而在另外一些机器运行则出错，为什么？

```c
#include <stdio.h>
int main(void)
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
```

因为 `getc` 和 `getchar` 的返回值类型是 int，而不是 char

而 EOF 经常被定义为 -1，因此如果系统使用的是无符号字符类型，那么 c 的值不可能等于 EOF，程序会进入死循环

## 5.5 如何对标准 I/O 流使用 fsync 函数？

先调用 `fflush`，冲洗内存缓冲区的数据

然后调用 `fsync`，其中文件描述符参数由 `fileno` 得到

## 5.6 为什么部分交互程序打印的提示信息没有包含换行符，也没有调用 fflush，还能输出提示信息？

程序交互运行时，标准输入和标准输出均为行缓冲，而调用 `fgets` 时会自动冲洗标准输出

## 5.7 使用 funopen 为 FreeBSD 和 Mac OS X 实现 fmemopen