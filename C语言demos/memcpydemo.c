#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *src = "hello ,sexy girls!!!"; //注意：这个用sizeof是得不到字符串的长度的，字符数组才可以
    char dst[100];
    memccpy(dst, src, 1, strlen(src) + 1); //
    printf("dst=%s\n", dst);
    memset(dst, 0, sizeof(dst));
    char *src1 = "hello\0sexy girls!!!";
    strncpy(dst, src1, strlen(src) + 1); //这个函数只要遇到'\0'就会返回，'\0'后面的内容不能复制到dst中
    printf("dst2=%s\n", dst + strlen("hello") + 1);
    //memccpy(dst, src1, 1, strlen(src) + 1);
    memcpy(dst, src1, strlen(src) + 1); //这个函数遇到'\0'不会返回，它复制src中所有内容到dst包括'\0'

    printf("dst3=%s\n", dst + strlen("hello") + 1);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];
    memcpy(b, a, 10 * sizeof(int));
    //memcpy(b, a, sizeof(a)); //还可以用来拷贝数组，第三个参数是需要拷贝的内存的大小，而不是元素个数
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        printf("%d, ", b[i]);
    }

    return 0;
}
