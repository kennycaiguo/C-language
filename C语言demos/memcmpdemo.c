#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];
    // int res = memcmp(b, a, sizeof(a)); //1
    int res = memcmp(a, b, sizeof(a)); //-1
    printf("result=%d\n", res);
    memcpy(b, a, sizeof(a));

    int res2 = memcmp(b, a, sizeof(b) - 2);
    printf("result2=%d\n", res2);
    return 0;
}
