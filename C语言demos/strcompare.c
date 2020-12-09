#include<stdio.h>
#include<string.h>

int main() {
    char a[]="hello";
    char b[]="hello girls";
    int flag = strncmp(a,b,5);
    if (flag>0)
    {
          printf("a[] > b[]");
    }else  if (flag<0)
    {
         printf("a[] < b[]");
    } 
    else
    {
        printf("a[]==b[]");
    }
    
    return 0;
}