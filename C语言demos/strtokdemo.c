#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /*
      使用strtok函数注意：1.该函数会破坏源字符串，所以最好构造一个备份在来切割
                         2.第二次调用该函数，第一个参数要设置为NULL，否则得不到正确结果
    
    */
    char str[]="sexy licks,nice boots,big butt,long legs";
    char tmp[100]={0};
    strcpy(tmp,str);
    char * res=strtok(tmp,",");
    while(res!=NULL){
        printf("res=%s ,",res);
        res = strtok(NULL,",");
    }
    return 0;
}
