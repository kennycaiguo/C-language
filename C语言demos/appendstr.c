#include<string.h>
#include<stdio.h>

int main() {
    char src[]=" let me caress your body!!!";
    char dst[]="girl";
    //strcat(dst,src); //girl let me caress your body!!!
    strncat(dst,src,18); //girl let me caress you
    printf("dst:%s",dst);
    return 0;
}