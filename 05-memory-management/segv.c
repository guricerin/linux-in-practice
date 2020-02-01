#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;
    puts("before invalid access");
    // 不正なアドレスにアクセスしてみる
    *p = 0;
    puts("after invalid access");
    exit(EXIT_SUCCESS);
}