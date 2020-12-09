#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 5; i++)
    { 
         
         int num = rand();//不一定需要seed，没有也可以
         printf("num=%d ,",num);
    }
    
    
    return 0;
}