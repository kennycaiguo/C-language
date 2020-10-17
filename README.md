# C-language
# <a href="https://www.w3cschool.cn/cadvance/izeb1j6f.html">C语言 函数指针</a>
# <a href="https://www.runoob.com/cprogramming/c-recursion.html">C语言函数的递归调用</a>
# C语言中使用可变参数
实例，开发工具为Clion，编译器使用MinGW64 8.1
#include <stdio.h>
#include <stdarg.h>



int AnySum(int count,...) { //求任意个数整数的和（参数count指定个数）
    va_list args;
    int sum = 0;
    va_start(args,count);
    for(int i=0;i<count;i++){
        sum = sum + va_arg(args, int);
    }
    va_end(args);
    return sum;


}

int AnyAvg(int n, ...) ////求任意个数整数的平均值（参数count指定个数）
{
    va_list arg;
    int i = 0;
    int sum = 0;
    va_start(arg, n);
    for (i = 0; i < n; i++)
    {
        sum = sum + va_arg(arg, int);
    }
    return sum / n;
    va_end(arg);
}
int AnyMul(int n, ...) //求任意个数整数的乘积（参数count指定个数）
{
    va_list arg;
    int i = 0;
    int sum = 1;
    va_start(arg, n);
    for (i = 0; i < n; i++)
    {
        sum = sum * va_arg(arg, int);
    }
    return sum ;
    va_end(arg);
}

/*int AnyMax(int count,...){
    va_list args;
    int max = 0;

    va_start(args,count);///初始化pArgs指针，使其指向第一个可变参数。
    max = *args; //将第一个可变参数的值赋给max，作为max的开始值,当第一个可变参数的值小于-120时程序不能得到正确结果
    printf("%d",max);
    for(int i=1;i<=count;i++){
        int tmp = 0;
        tmp = va_arg(args,int);
        if(max < tmp){
            max = tmp;
        }
    }

    return max;
    va_end(args);
}*/

int AnyMax(int count,...){ //求任意个数整数的最大值（参数count指定个数）
    va_list args; //这个宏用来接收可变参数的地址
    va_start(args,count);///初始化pArgs指针，使其指向第一个可变参数。
        int max = va_arg(args,int);
    va_start(args,count);
        int tmp = 0;
         for(int i=0;i< count;i++){

             tmp = va_arg(args,int);

             if(max < tmp){
                 max = tmp;
             }
         }
         va_end(args);
           return max;


}

int AnyMin(int count,...){ //求任意个数整数最小值（参数count指定个数）
    va_list args; //这个宏用来接收可变参数的地址
    va_start(args,count);///初始化pArgs指针，使其指向第一个可变参数。
        int min = va_arg(args,int);
    va_start(args,count);
        int tmp = 0;
         for(int i=0;i< count;i++){

             tmp = va_arg(args,int);

             if(min > tmp){
                 min = tmp;
             }
         }
         va_end(args);
           return min;


}

int main(){
  /* int sum =AnySum(5,12,22,33,44,55);
   printf("sum=%d",sum);*/
  //int max = AnyMax(5,-10000,-2000,-3000,-4000,-5000);
 /*  int max = AnyMax(3,500,-2,-10);
   int min =AnyMin(3,500,-2,-10);
  printf("max = %d,min = %d\n",max,min);
*/

 int multotal = AnyMul(4,1,-2,3,4);
 printf("multotal=%d",multotal);
   return 0;
}
