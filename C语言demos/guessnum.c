#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("**********************猜数字游戏*********************");
    srand((unsigned int)time(NULL));
    int geussnum;
    int ran_nums[4];
    int guess_nums[4];
    //create random number from 0 to 9
    int i;
    for(i=0;i<4;i++){
        ran_nums[i]=rand()%10;
    }
    while(1) {
        printf("请输入一个4位数：");
        scanf("%d",&geussnum);
        guess_nums[0]=(geussnum/1000)%10;
        guess_nums[1]=(geussnum/100)%10;
        guess_nums[2]=(geussnum/10)%10;
        guess_nums[3]=geussnum%10;
        int n=0;
        for(i=0;i<4;i++){
            if(guess_nums[i]>ran_nums[i]){
                printf("第%d位大于正确数字\n",i+1);
            }else if(guess_nums[i]<ran_nums[i]){
                printf("第%d位小于正确数字\n",i+1);
            } else{
                printf("第%d位数字正确\n",i+1);
                n++;
            }
            if(4==n){
                exit(0);
            }
        }
    }
    return 0;
}