#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /*  int arr[10];
    memset(arr, 0, sizeof(arr));//这个写法最常用，中间的参数一般传0
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    } */

    /*  int c;
    memset(&c, 97, sizeof(c)); //第二个参数是以字符的方式传入，它是ascii码，所以该函数常用来清零
    printf("c=%c\n,c2=%d", c, c); */

    int arr[10];
    memset(arr, 'x', sizeof(arr)); //memset函数的主要作用是清零
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]=%c\n", i, arr[i]);
    }

    return 0;
}
