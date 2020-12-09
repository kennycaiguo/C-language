#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //char src[]="hello girls i want to say hello and have fun with you";
    char src[]="hello girls  hello sexies and hello lovers ,have fun and say hello to you mom";
    char* p=strstr(src,"hello");
    char tmp[20];
    
    int i=0;
    if(p==NULL){
        printf("你查找的字符串不存在\n");
    } else
    {
       while (p!=NULL)
       {
           strncpy(tmp,p,sizeof("hello"));
           printf("%s ",tmp);
           p =strstr(p+1,"hello");
       }
       
    }
    
    return 0;
}
