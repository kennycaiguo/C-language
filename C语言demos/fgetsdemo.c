#include<stdio.h>
#include<string.h>

//c语言中，字符串的输出有三种方式:printf("str=%s",str)，puts(str),fputs(str,stdout)
int main() {
//     printf("请输入一句话：");
//     char str[100]={0};
//     fgets(str,100,stdin);
//     //printf("str=%s",str);
//    // puts(str);
//    fputs(str,stdout);
    // char str[]="\0hello girls";
    
    char str[100]="mike";
     int len = strlen(str);
     printf("len=%d\n",len); //4
     printf("size=%d\n",sizeof(str)); //100
    return 0;
}