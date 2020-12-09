#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char src[]="hello girls i want to say hello and have fun with you";
    char* p=strchr(src,'h');
    char dst[20]={0};
    int i=0;
    if(p==NULL){
        printf("你查找的字符不存在\n");
    } else
    {
       while (p!=NULL)
       {
           printf("%c ",*p);
           p =strchr(p+1,'h');
       }
       
    }
    
    return 0;
}
