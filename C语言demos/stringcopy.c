#include<stdio.h>
#include<string.h>

int main() {
    char src[100]="hello\0 girls";
    char dest[100];
    char* res;
    res=strncpy(dest,src,13);
    //fputs(dest,stdout);
    // int i;
    // for(i=7;i<13;i++){
    //     printf("%c",dest[i]);
    // }
    printf("dest=%s",res);
    return 0;
}