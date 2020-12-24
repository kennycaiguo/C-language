#include <stdio.h>
union un
{
    unsigned char a;
    unsigned short b;
    unsigned int c;
};

int main(int argc, char const *argv[])
{
    union un tmp;
    //共用体中所有成员的地址是一样的
    printf("%p,%p,%p\n", &(tmp.a), &(tmp.b), &(tmp.c));
    //共用体的大小为共用体中最大的成员的大小
    printf("%lu\n", sizeof(tmp)); //4,因为这里最大的成员是int类型占4个字节
    //对共用体一个成员的赋值会影响另外的成员
    tmp.c = 0x44332211;
    //左边的高位，右边是低位//
    //低位放低地址，高位放高地址
    printf("%x\n", tmp.a); //11 这里a是最低位，因为a的大小最小
    printf("%x\n", tmp.b); //2211 c是次低位
    tmp.a = 0x00000055;
    printf("%x\n", tmp.c); //44332255 b是最高位
    printf("%x\n", tmp.b); //2255
    printf("============================\n");
    tmp.b = 0x6677;
    printf("%x\n", tmp.c); //44336677
    printf("%x\n", tmp.a); //77，a是最低位，所以c的最低位的值给了a
    return 0;
}
