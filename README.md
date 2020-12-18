# C-language
# <a href="https://zhuanlan.zhihu.com/p/36654741">使用 Visual Studio Code 搭建 C/C++ 开发和调试环境</a>
# <a href="https://zhuanlan.zhihu.com/p/84828775">c语言操作mysql数据库</a>
# <a href="https://www.jianshu.com/p/5b80aa05199a">c语言操作mysql数据库</a>
# <a href="https://www.w3cschool.cn/cadvance/izeb1j6f.html">C语言 函数指针</a>
# <a href="https://www.runoob.com/cprogramming/c-recursion.html">C语言函数的递归调用</a>
# <a href="https://gitee.com/andyspider/Camkit">Camkit是一个摄像头相关的工具箱，使用C语言写成</a>
# <a href="https://cloud.tencent.com/developer/article/1658626">c语言单链表的实现</a>
# <a href="https://www.cnblogs.com/lifuqing/archive/2011/08/20/list.html">C语言单链表实现19个功能完全详解</a>
# <a href="http://c.biancheng.net/cpp/u/hanshu/">C语言函数手册：c语言库函数大全|C语言标准函数库|c语言常用函数查询</a>
# <a href="https://www.w3cschool.cn/cyykhsscsc/">C语言库函数速查手册-编程狮</a>
# <a href="https://github.com/kennycaiguo/awesome-c-cn">C语言 资源大全中文版</a>
# <a href="https://www.cnblogs.com/traditional/p/11511685.html">《python解释器源码剖析》第0章--python的架构与编译python</a>
# <a href="https://my.oschina.net/u/4042528/blog/3103418">教你阅读 Cpython 的源码（一）</a>
# <a href="https://flaggo.github.io/python3-source-code-analysis/preface/code-organization/">Python 源代码的组织以及下载</a>
# <a href="https://github.com/kennycaiguo/cpython">python源代码</a>
# <a href="https://juejin.im/post/6850037282893332487">写Java这么久，JDK源码编译过没？编译JDK源码踩坑纪实，老带劲了</a>
# <a href="https://jdk.java.net/archive/">Jdk源码</a>
# <a href="https://developer.aliyun.com/article/574676">Javac编译原理</a>
# <a href="https://mp.weixin.qq.com/s/tXilzUzN7cDhnc3ztw4Vlw">这才是你需要的C语言、C++学习路线！</a>	
# <a href="http://c.biancheng.net/cpp/html/2790.html">C语言实现动态数组，克服静态数组大小固定的缺陷</a>
# <a href="https://blog.csdn.net/weibo1230123/article/details/81427666">C语言内存管理超详解</a>
# <a href="https://blog.csdn.net/second60/article/details/79946310">C语言内存模型详解</a>
# <a href="https://zhoushisong.cn/2018/01/09/C%E8%AF%AD%E8%A8%80%E5%86%85%E5%AD%98%E8%AF%A6%E8%A7%A3/">C语言内存详解 </a>
# <a href="https://blog.csdn.net/weixin_43701019/article/details/99546686?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param">用C语言实现可添加删除元素的数组（两种方式，数组和指针）</a>
# <a href="https://blog.csdn.net/hcu5555/article/details/20555229">gets函数完美替代</a>
# 注意：c语言严重错误代码
         //int nums[5] = {1,2,3,5,6};
	//int* pNum = (int*)realloc(nums, 10);不能将一个静态数组的内存空间进行扩容！！！
        //int* p；//*p=5；这个是错误的必须先要保证p指向合法的单元，然后才能这样子赋值，也就是说p必须先初始化
	
# 在vs2013中将汇编代码嵌入c语言源程序中：

#include "stdafx.h"
#include<stdlib.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int b;
	int c;

	__asm
	{
		mov a, 3
		mov b, 4
		mov eax, a
		add eax, b
		mov c, eax
	}
	printf("result=%d\n", c);
	system("pause");
	return 0;
}

结果：result=7

# c语言利用ascii码输出26个小写字母
#include <stdio.h>

int main()
{
    char ch;
    int i;
    for(i=97;i<=123;i++){
        ch=i;//注意：char类型的本质是8为的整数，所以可以直接给它赋整数值
        printf("%c ",ch);//这里可以将26个小写字母按照顺序输出到屏幕
    }

    return 0;
}

结果：
a b c d e f g h i j k l m n o p q r s t u v w x y z

# 用c语言实现计算字符串长度的函数,其实使用sizeof较好
int getStringLength(char* s){ //字节实现的计算字符串长度的函数
	int i = 0;
	while (*s != '\0'){
		++i;
		s++;
	}
	return i;
}
# c语言实现将一个小写的字符转换为大写和将一个大写的字符串转为小写，vs2013版本
#include "stdafx.h"
#include<string.h>
#include<malloc.h>

int getStringLength(char* s){ //字节实现的计算字符串长度的函数
	int i = 0;
	while (*s != '\0'){
		++i;
		s++;
	}
	return i;
}


char* toUpper(char* s){
	char tmp = 0;
	int len = strlen(s);
	char* res = (char*)malloc(sizeof(char)*len+1);//需要加1，存放0
	int i = 0;
	while (*s != '\0'){
		if (*s >= 97 && *s <= 123){
             tmp = *s;
		     tmp = tmp - 32;
		     res[i] = tmp;
		}
		else{
			res[i] = *s;
		}
		s++;
		i++;
	}
	if (res[len] != 0){ //注意这里没有'\0',因为根据循环条件当*s='\0'时，循环结束了
		res[len] = 0;
	}
	return res;
}

char* toLower(char* s){
	char tmp = 0;
	int len = strlen(s);
	char* res = (char*)malloc(sizeof(char)*len + 1);//需要加1，存放0
	int i = 0;
	while (*s != '\0'){
		if (*s >= 65 && *s <= 91){
			tmp = *s;
			tmp = tmp +32;
			res[i] = tmp;
		}
		else{
			res[i] = *s;
		}
		s++;
		i++;
	}
	if (res[len] != 0){ //注意这里没有'\0',因为根据循环条件当*s='\0'时，循环结束了
		res[len] = 0;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* s = "hello,busty girls,i am coming!!!";//这个是字符串
	 
	/*printf("the length is %d\n", getStringLength(s)); //利用自己的函数实现计算字符串长度，不包含'\0'
	printf("the length is %d", strlen(s));*/
	char* s2 = "GIVE ME YOU PUSSY ,LALALA..."; 
	printf("result=%s\n", toUpper(s));
	printf("result=%s\n", toLower(s2));
	getchar();
	return 0;
}

# c语言字符指针的简单应用
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[20] = {0};
    char *p = str;
    int i;
    char j;
    for (i = 0, j = 'a'; i < 10, j < 'j'; i++, j++)
    {
        //str[i] = j;
        *(p + i) = j;
    }
    printf("str=%s", str);
    return 0;
}
## 结果：str=abcdefghi

# c语言字符串的输出方式
#include<stdio.h>

//c语言中，字符串的输出有三种方式:printf("str=%s",str)，puts(str),fputs(str,stdout)
int main() {
    printf("请输入一句话：");
    char str[100]={0};
    fgets(str,100,stdin);
    //printf("str=%s",str);
   // puts(str);
   fputs(str,stdout);
    return 0;
}
# atoi库函数的实现原理
#include <stdio.h>
int my_atoi(char *str)
{
    char *tmp = str;
    int flag = 0; //0代表正数，1代表负数
    if (*tmp == '-')
    {
        flag = 1;
        tmp = tmp + 1; //从第二个字符开始转换
    }
    else if (*tmp == '+')
    {
        tmp = tmp + 1;
    }
    int num = 0;
    while (*tmp != '\0')
    {
        num = num * 10 + (*tmp - '0');
        tmp++;
    }
    if (0 == flag)
    {
        return num;
    }
    else
    {
        return -num;
    }
}
int main(int argc, char const *argv[])
{
    printf("num1=%d\n", my_atoi("+123"));
    printf("num2=%d\n", my_atoi("-123"));
    printf("num3=%d\n", my_atoi("123"));
    return 0;
}


# c语言实现将用户输出的字符串保存到一个文本文件中，输入exit显示good bye，如何按回车退出

#include "stdafx.h"
#include<string.h>
 

int _tmain(int argc, _TCHAR* argv[])
{
	FILE* f;
	f = fopen("input.txt", "w+");
	char input[50] = "\0";
	 
	printf("请输入内容,exit退出：");
	int i = 0;
	while (strcmp(input, "exit") != 0)
	{   
		gets(input);
		 
		if (strcmp(input, "exit") != 0){
			 fwrite(input, 1, strlen(input), f); 
			 fprintf(f, "\n");
			memset(input, '\0', 50);
		}
		else{ 
			printf("good bye!");
			fflush(f);
			fclose(f);
		}
	}

	getchar();
	return 0;
}


# c语言产生随机数的简单例子1. //vscode版本，gcc编译，不够好，每一次都产生一样的数组，实例2会好一点，因为使用时间戳，保证每一次都不一样
#include<stdio.h>
#include<stdlib.h>

int main() {
    srand(rand());
    int num = rand();//不一定需要seed，没有也可以
    printf("random number:%d",num);
    return 0;
}
# c语言随机数实例2，vscode开发
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand((unsigned int)time(NULL));
     
    for (int i = 0; i < 5; i++)
    { 
         
         int num = rand(); 
         printf("num=%d ,",num);
    }
    
    
    return 0;
}
结果：测试了四次
第一次：
num=10289 ,num=28007 ,num=13881 ,num=30550 ,num=29303 ,
第二次：
num=10347 ,num=24870 ,num=7756 ,num=4937 ,num=18357 ,
第三次：
num=10413 ,num=10462 ,num=4591 ,num=27452 ,num=28040 ,
第四次：
num=10468 ,num=29345 ,num=13370 ,num=10544 ,num=6780 ,

# c语言猜4位数游戏
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

# c语言中，两数相除得到小数的问题
#include <stdio.h>

int main()
{
    //在c语言中，如果想得到小数商，则相除的两个数必须至少有一个是小数，整数变为小有一个小技巧，就是将其乘于1.0
    int a=5;
     float b=3.0;
    float c=a/b;
    printf("result=%f",c);

    return 0;
}

# 后置++和前置++的区别
#include<stdio.h>
int main()
{
   //后置++
     int a=1;
     int b=0;
     b=a++; //注意，这里跟 a++;b=a;是有区别的，应该是：b=a;a++;
     printf("a=%d,b=%d",a,b);//a=2,b=1
     //前置++
     int x=1;
     int y=++x;
      printf("x=%d,y=%d",x,y);//x=2,y=2

    return 0;
}

# c语言实现数组反转功能
#include<stdio.h>
#include<malloc.h>

//该函数实现数组反转功能，写法1，有返回值
int* reversearray(int* pArr,int n){
    int* pTemarr=(int*)malloc(sizeof(int)*n);
    int i,j;
    for(i=n-1,j=0;i>0,j<n;i--,j++){
        pTemarr[j] = pArr[i];
    }

    return pTemarr;
}
//写法2，没有返回值
void reversearray2(int* pArr,int n){
    int* pTemarr=(int*)malloc(sizeof(int)*n);
    int i,j;
    for(i=n-1,j=0;i>0,j<n;i--,j++){
        pTemarr[j] = pArr[i];
    }
    for(i=0;i<n;i++){
        pArr[i] =pTemarr[i];
    }
    free(pTemarr);//没有需要再使用这个内存空间，所以就把它释放，以防内存泄漏
    return ;
}
# //写法3，使用while循环，非常好
void reversearray3(int* pArr,int n){
    int tmp;
    int i=0;
    int j=n-1;
    while(i<j){
        tmp=pArr[j];
        pArr[j]=pArr[i];
        pArr[i]=tmp;
        i++;
        j--;
    }
 
}

int main()
{
   int arr[5]={1,2,3,4,5};
    int *parr= reversearray(arr,5);
    int i;
    for(i=0;i<5;i++){
        printf("parr[%d]=%d ",i,parr[i]);
    }
    return 0;
}
结果：
parr[0]=5 parr[1]=4 parr[2]=3 parr[3]=2 parr[4]=1
# 注意:c语言中，二进制位全部位零的含义：
## 1.数值零
## 2.字符串的结束标记'\0'
## 3.空指针NULL
## NULL的本质也是零，而这个零不代表数值零，而表示是内存单元的不会零
# 计算机规定了，以零为编号的存储单元的内容不可读也不可写
# c语言位运算与逻辑运算实例
#include "stdafx.h"
//位运算符实例

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 5;
	int j = i << 2; //20 左移会变大
	int k = i >> 2; //i  右移会变小
	//printf("%d,%d", j, k);// 20,1
	//printf("%d\n", j&k); //20&1=0;
	//printf("%d", j|k); //20|1=21
	//printf("%d", j ^ k); //20^1 = 21;
	//printf("%d,%d", ~j,~k); //~20 =-21,~1=-2;
	//printf("%d", ~(-j)); //~(-20)=19;
	printf("%d", ~(-k)); //~(-1)=0;
	printf("%d\n", j&&k); //1 逻辑与，j和k都是真，结果位真
	printf("%d", j||k); //1 逻辑或，只要有一个为真，就为真
	getchar();
	return 0;
}

# c 语言的补码问题
正数的补码是它的二进制形式，
负数的补码求法：
先将负数的绝对值转为二进制形式，然后各位取反，末尾加1，如果位数不够，则在左边用1补齐
如：求-3的补码：
1）将-3的绝对值3变为二进制011，然后然后各位取反=》100，末尾加1=》101，
如果以十六进制删除，就要在左边不13个q1=》1111 1111 11111 -101，所以运行以下程序（vs2013版本）
#include<stdio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	int x = -3;
	printf("%#X", x);//0XFFFFFFFD
	getchar();
	return 0;
}

得到的结果是 0XFFFFFFFD（1111 1111 1111 1101的十六进制写法）

实例2
int _tmain(int argc, _TCHAR* argv[])
{
	 
	int a = 0xFFFFFFEF;//-17
	printf("%d", a);
	getchar();
	return 0;
}
结果：-17
# c语言的指针问题，vs版本，使用c++编译器，不过它是兼容c的，没有问题
## 实例1：
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//int arr[] = {1,2,3,4,5};
	//int *p = arr; //注意：数组名代表数组首地址，此时p指向元素1
	//p++; //指针向右移动一位，此时指针指向元素2
	//printf("p指向的内容：%d", *p); //2
	char *str = "hello world"; //字符串就是字符数组，数组名代表数组首地址
	char *p1 = str;
	//printf("p1指向的字符%c", *p1); //h，这里ok
	p1++;
	printf("p1指向的字符%s", p1);//ello world,%s表示输出从p1指向的位置开始输出剩余的所有字符，printf("p1指向的字符%s", *p1);会报错，因为p1指向的内容是一个字符
	char** p2 = &p1;
	//printf("p2指向的内容%s",*p2);//hello world *p2相当于p1
	printf("p2指向的内容%d", p2);//p2指向的内容18283652，这个相当于p1的地址，是一个整数
	//printf("p2指向的内容%s", **p2); //报错**p2，这里是字符，不能用字符串的格式
	//printf("p2指向的内容%c", **p2); //h **p2相当于p1指向的字符，所以要用%c
	char* str2 = "我想聊美女";
	char* sp = str2;//注意：在unicode编码中，一个汉字占2个字节，所以移动一个汉字的位置，字符指针需要移动2次，否则程序乱码
	sp++;
	sp++;
	printf("%s", sp);// "想聊美女";
	sp++;
	sp++;
	printf("%s", sp);//"聊美女";
	getchar();
	return 0;
}

# c语言指针问题 实例2
#include "stdafx.h"
void swap(int* p, int* q){ //这样子是不能互换a,b的值
	int* t;
	t = p;
	p = q; //只是修改p的值，p指向的地址的值没有改变
	q = t; //只是修改q的值，q指向的地址的值没有改变
}

void swap2(int* p, int* q){ //是才能互换a,b的值
	int t;
	t = *p; 
	*p = *q;//不是要修改p的值，而是要修改p所指向的地址的值
	*q = t;//不是要修改p的值，而是要修改p所指向的地址的值
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 3, b = 5;
	swap2(&a, &b);
	printf("a=%d,b=%d", a, b);
	getchar();
	return 0;
}

# C语言指针实例3，利用指针输出数组的所有元素，vs2013版
#include "stdafx.h"
void outputArr(int* pArr, int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d\n", *(pArr + i));//pArr[i]=*(pArr+i)

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = { 11, 22, 33, 44, 55 };
	//printf("%#X\n", a);//0XB3FC9C 数组名称保存的是第一个元素的地址,它是一个指针常量
	//printf("%#X\n", &a[0]);//0XB3FC9C
	//a = 55; //报错：不能给常量赋值
	outputArr(a, 5);
	getchar();
	return 0;
}

# c语言中的指针数组实例 ，vscode版本
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[3] = {10, 20, 33};
    int *p[3]; //指针数组
    int i;
    for (i = 0; i < 3; i++)
    {
        p[i] = &a[i];
        /* code */
        //printf("*p[%d]=%d,", i, *p[i]);//这个跟下面的写法等价
        printf("*p[%d]=%d,", i, *(*(p + i))); //注意：指针数组的数组名其实是指针的指针
    }

    return 0;
}


# c语言判断一个数是否是素数

#include <stdio.h>
//判断一个数字是否是素数,也就是只能被1和它本身整除的数
int isSuShu(int val){
     if(val==1){ //如果val为1，就直接返回假，因为安装规定，1不是素数
         return 0;
     }
     if(val==2){ //如果val是2，就直接返回真
         return 1;
     }

    for(int i=2;i<val;i++){//否则，判断val是否能被2~val-1中的任何数整除，只要能被其中一个数整除，返回假
        if(val%i==0){
            return 0;
        }

    }

    return 1;//如果遍历了2~val-1中的所有数，都不能整除，返回真
}

int main() {
    int val=7;
    int res=isSuShu(val);
    if(res){
        printf("%d是素数",val);
    }else{
        printf("%d不是素数",val);
    }

    return 0;
}
结果:
7是素数
# c语言输出0到指定数字val中的所有素数，vs版
#include "stdafx.h"

bool isPrimeNum(int val){
	if (val == 1)return false;
	for (int i = 2; i < val; i++){
		if (val%i == 0){
			return false;
		}
	}
	return true;
}
void printPrimeNums(int val){// ## 输出0到指定数字中的所有素数的算法函数
	int i, j;
	for (i = 2; i < val; ++i){
		for (j = 2; j < i; ++j)
		{
         if (i%j == 0){
			 break;
		  }
		
		}
		if (j == i){
			printf("%d\n", i);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[]) //vs格式的文件cpp但是兼容c的
{
	/*int i = 7;
	if (isPrimeNum(i)){
		printf("%d is a prime number",i);
	}
	else
	{
		printf("%d is not a prime number",i);
	}*/
	printPrimeNums(100);
	getchar();
	return 0;
}

# c语言斐波那契数列的非递归算法
 #include <stdio.h>

int main() {
    int f1=1;
    int f2=2;
    int f3;
    int n;
    printf("请输入要求的项");
    scanf("%d",&n);
    if(1==n){
        f3=1;
    }else if(2==n){
       f3=2;
    }else{
        for(int i=3;i<=n;++i){
             f3 = f1 + f2;
             f1 = f2;
             f2 = f3;
        }
    }


    printf("第%d项的结果是：%d\n",n,f3);
    return 0;
}

# c语言斐波那契数列的递归算法
#include <stdio.h>

void fabonaci(int i);

double factorial(unsigned int i)
{
    if(i <= 1)
    {
        return 1;
    }
    return i * factorial(i - 1);
}

int fibonaci(int i) {
    if(i==0){
        return 0;
    }
    if(i==1){
        return 1;
    }
    return fibonaci(i-1) + fibonaci(i-2);
}

int  main()
{
   /* int i = 15;
    printf("1*...*%d=%f\n", i, factorial(i));
    return 0;*/
   for(int i=0;i<10;i++){
       printf("%d ",fibonaci(i));
   }

}

# c语言求解一元二次方程
#include <stdio.h>
#include <math.h>
//c语言解一元二次方程
int equation(){
    double a,b,c;
    double delta;
    double x1,x2;
    char ch;
    do{
        printf("请输入三个整数：\n");
        printf("请输入第一个整数：\n");
        scanf("%lf",&a);
        printf("请输入第二个整数：\n");
        scanf("%lf",&b);
        printf("请输入第三个整数：\n");
        scanf("%lf",&c);
        delta=b*b-4*a*c;
        if(delta > 0){
            x1 = (-b+sqrt(delta))/2*a;
            x2 = (-b-sqrt(delta))/2*a;
            printf("有两个解：x1=%lf,x2=%lf\n",x1,x2);
        } else if(0==delta){
            x1=x2=(-b/2*a);
            printf("有唯一解：x1=x2=%lf\n",x1);
        }else{
            printf("无实数解！\n");
        }
        printf("输入y求解下一个方程，n或其他字符结束:\n");
        scanf(" %c",&ch);//前面必须加一个空格
       /* if('n'==ch||'N'==ch){
            break;
        }*/

    }while('y'==ch||'Y'==ch);


}
int main() {
    equation();
    return 0;
}



# c语言判断一个数是否回文数
#include <stdio.h>
 
int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;
 
    printf("输入一个整数: ");
    scanf("%d", &n);
 
    originalInteger = n;
 
    // 翻转
    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }
 
    // 判断
    if (originalInteger == reversedInteger)
        printf("%d 是回文数。", originalInteger);
    else
        printf("%d 不是回文数。", originalInteger);
    
    return 0;
}
运行结果：

输入一个整数: 12321
12321 是回文数
# c语言中的逗号表达式
#include <stdio.h>
//逗号表达式有什么用？在一个逗号表达式中有若干个表达式，但是整个表达式的值是最坏一项
int main() {
     int j=2;
    int i=(j++,++j,j+2,j-3);//注意，++是会改变j的值，但是如果j+2的结果没有赋值给j，j仍然是原理的值

    printf("i=%d\n",i); //i=1
    return 0;
}

# c语言中++1和i++的区别
#include <stdio.h>
//++i与i++的区别,++i->整个表达式的值是i+1之后的值，i++->整个表达式的值是i+1之前的值
int main() {
    int i,j,k,l;
    i=j=3;
    k=++i;//4 =>i=i+1;k=i;先自增，在赋值
    l=j++;//3 =>l=j;l=l+1；先赋值，在自增

    printf("k=%d\n",k);//k=4
    printf("l=%d\n",l);//l=3
    return 0;
}


# 用c语言计算1+1/2+...+1/100的结果 （注意：在c语言在如果int j=1/2，那么j=0；正确的写法float j=1/2.0，那么j=0.5000）
#include <stdio.h>
//计算1+1/2+。。。+1/100
float FenshuAdd(){
    int i=1;
    float sum=0;
    while(i<=100){
        float j=1/(float )i;
        sum+=j;
        ++i;
    }
    /*for(i=1;i<=100;++i){
        float j = 1/(float)i;
        printf("j=%f\n",j);
        sum+=j;
       //printf("sum=%.mf\n",sum);
    }*/

    return sum;
}
int main() {
    printf("1+1/2+..+1/100=%f\n",FenshuAdd());
    return 0;
}

# c语言统计字符串出现的次数
#include <stdio.h>
#include <string.h>

int countStr(const char *str,const char *lookStr);

int main() {
    char str[]="welcome to china,welcome to guandong,welcome to donggun,welcome to zmt";
    char *looup="come";
   
    int i=countStr(str,looup);
    printf("times:%d",i);

    return 0;
}

int countStr(const char *str,const char *lookStr) {
    char *c1=strstr(str, lookStr);//come:come to china,welcome to guandong,welcome to donggun,welcome to zmt
    int i=0;
    while (c1!=NULL){
        printf("result:%s\n",c1);
        c1++; //要移动指针位置，否则会变成死循环
        i++;
        c1=strstr(c1, lookStr);
    }
    return i;
}
# c语言换行输出一个字符串的所有字符
void printChars(const char* str) {

       int len=strlen(str)/sizeof(str[0]);//获取字符数组的长度
       for(int i=0;i<len;i++){
           printf("%c\n",str[i]);
       }
}

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

# c语言使用冒泡排序法实现数组的排序，vs2013版本
#include "stdafx.h"
#include<malloc.h>

int getMax(int* parr,int  n){
	int max = *parr;
	for (int i = 0; i < n; i++){
		if (max < *(parr + i)){
			max = *(parr + i);
		}

	}
	return max;
}

void sort(int* a, int len){
	int t;
	for (int i = 0; i<len - 1; ++i){
		for (int j = 0; j<len-1-i; ++j){
			if (a[j]>a[j + 1]){
               t = a[j];
			   a[j] = a[j + 1];
			   a[j + 1] = t;
			}
			
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[6] = { 2, 8, -8, 0, 10, 11 };
	printf("max=%d\n", getMax(arr,6));
	sort(arr,6);
	for (int i = 0; i < 6; i++){
		printf(" arr[%d] = %2d", i,arr[i]);
	}
	getchar();
	return 0;
}

结果：
max=11
 arr[0] = -8 arr[1] =  0 arr[2] =  2 arr[3] =  8 arr[4] = 10 arr[5] = 11


# c语言操作Oracle数据库
C语言操作Oracle数据库，开发工具：Clion 1， 将I:\Software\oracle数据库\c语言操作Oracle数据库的依赖库项目下面的ocilib4.7.0文件夹复制到d:\programs(最终变成D:\Programs\ocilib4.7.0) 2， 在Clion中创建一个c语言项目 3， 配置CmakeList.txt文件，内容如下 cmake_minimum_required(VERSION 3.16) project(oracleOp C)

set(CMAKE_C_STANDARD 99) include_directories(D:\programs\ocilib4.7.0\include) link_directories(D:\programs\ocilib4.7.0\lib64) link_libraries(ociliba) add_executable(oracleOp OracleOp.c)

4.将D:\programs\ocilib4.7.0\lib64\ ociliba.dll复制到 cmake-build-debug目录下面(如果不复制，会出现程序运行正常，但是没有任何数据的现象) 4b.配置环境变量path，增加D:\programs\ocilib4.7.0\include 5.参考代码 #include <stdio.h> #include <tchar.h> #include "ocilib.h"

void err_handler(OCI_Error *err) { printf( "code : ORA-%05i\n" "msg : %s\n" "sql : %s\n", OCI_ErrorGetOCICode(err), OCI_ErrorGetString(err), OCI_GetSql(OCI_ErrorGetStatement(err)) ); }

int main(int argc, _TCHAR* argv[]) {

OCI_Connection* cn;
OCI_Statement* st;
OCI_Resultset* rs;


OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);

cn  = OCI_ConnectionCreate("127.0.0.1:1521/ORCL", "scott", "tiger", OCI_SESSION_DEFAULT);
 printf("%d\n",cn==NULL);
if(cn == NULL){
    err_handler(OCI_GetLastError());
    printf("%i",OCI_GetVersionServer(cn));
    printf("连接失败！\n");
}
st  = OCI_StatementCreate(cn);

OCI_ExecuteStmt(st, "select empno,ename,sal,deptno from emp");

rs = OCI_GetResultset(st);

while (OCI_FetchNext(rs)){
    printf("code: %i, name %s,salary %d,department# %d\n", OCI_GetInt(rs, 1)  , OCI_GetString(rs, 2),OCI_GetInt(rs, 3),OCI_GetInt(rs, 4));
}

printf("\n%d row(s) fetched\n", OCI_GetRowCount(rs));


OCI_Cleanup();


char a[20];
gets(a);

return EXIT_SUCCESS;
}

结果： code: 7369, name SMITH,salary 800,department# 20 code: 7499, name ALLEN,salary 1600,department# 30 code: 7521, name WARD,salary 1250,department# 30 code: 7566, name JONES,salary 2975,department# 20 code: 7654, name MARTIN,salary 1250,department# 30 code: 7698, name BLAKE,salary 2850,department# 30 code: 7782, name CLARK,salary 2450,department# 10 code: 7788, name SCOTT,salary 3000,department# 20 code: 7839, name KING,salary 5000,department# 10 code: 7844, name TURNER,salary 1500,department# 30 code: 7876, name ADAMS,salary 1100,department# 20 code: 7900, name JAMES,salary 950,department# 30 code: 7902, name FORD,salary 3000,department# 20 code: 7934, name MILLER,salary 1300,department# 10

14 row(s) fetched
# C 语言利用数组作为函数的形参
#include<stdio.h>

void showArrayElemants(int arr[], int size){ //注意：这里size就是数组的长度
    for(int i=0;i<size;i++){
        printf("element(%d): %d ",i,arr[i]);
    }
}

void main(){
     int a[]={2,3,6,7,9,14,56,45,65,67};
     int size = sizeof(a)/sizeof(a[0]);//获取数组的元素个数：数组的总长度/每个元素的长度
     showArrayElemants(a,size);//size跟数组的元素个数必须一样
}
 
# c语言动态创建一维数组，vs2013版本
#include "stdafx.h"
#include<malloc.h>
void printArr(int* pArr, int len){
	for (int i = 0; i < len; i++){
		printf("%2d ", pArr[i]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len = 5;
	int* dArr = (int*)malloc(sizeof(int)*len);//动态创建数组的原理
	for (int i = 0; i <5; i++){
		dArr[i] = i;
	}
	/*printf("%2d", dArr[0]);
	printf("%2d", dArr[1]);
	printf("%2d", dArr[2]);
	printf("%2d", dArr[3]);
	printf("%2d", dArr[4]);*/
	printArr(dArr,len);
	free(dArr);
	getchar();
	return 0;
}
# c语言实现动态数组的扩容
#include "stdafx.h"
#include<malloc.h>
void printArr(int* pArr, int len){
	for (int i = 0; i < len; i++){
		printf("%2d ", pArr[i]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len = 5;
	int* dArr = (int*)malloc(sizeof(int)*len);//动态创建数组的原理
	for (int i = 0; i <5; i++){
		dArr[i] = i*i;
	}
	
	printArr(dArr,len);
	printf("\n");
	dArr = (int*)realloc(dArr, 40); //数组动态扩容，可以保留原来的数据，但是必须要接收其返回值，不接受，结果就不正确
	/*printf("%3d", dArr[0]);
	printf("%3d", dArr[1]);
	printf("%3d", dArr[2]);
	printf("%3d", dArr[3]);
	printf("%3d", dArr[4]);*/
	printArr(dArr, 5);
	free(dArr);
	getchar();
	return 0;
}

# c语言结构体的使用，注意两种初始化方法的区别
#include "stdafx.h"
#include <string.h>

typedef struct Stu
{
	char* name;
	int age;
	char* gender;
	float score;
	void sayHi(){ //结构体里面是可以有方法的
		printf("hello i am %s\n", name);
	};
	void setName(char* newname){
		name = newname;
	};
	 
}Student;

int _tmain(int argc, _TCHAR* argv[])
{
	Student s = { "jack", 18, "male", 78.5 }; //结构体初始化方式一,这个比较好
	//printf("%s:%d:%s:%f", s.name,s.age,s.gender,s.score); //jack
	printf("hello i am %s,i am %d years old,i am a %s,my score is %f", s.name, s.age, s.gender, s.score); //ok
	//Stu s2;//结构体初始化方式二，这个不太好
	//s2.age = 18;
	//s2.name = "mary"; //这里要修改为 strcpy(s2.name,"mary')
	//s2.gender = "female"; //这里要修改为 strcpy(s2.gender,"female')
	//s2.score = 66.6;
	// printf("%s\n", s2); //mary
	// s2.sayHi();
	// s2.setName("Paula");
	// s2.sayHi();
	/* char* name = s2.name;
	 int age = s2.age;
	 char* gender = s2.gender;
	 float score = s2.score;
	 printf("hello i am %s,i am %d years old,i am a %s,my score is %s", name, age, gender, score);*/ //报错
	getchar();
	return 0;
}
# C语言链表的基本操作
## 实例1
  #include<stdio.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
    
}Node;

Node* createList(){
    Node *first,*second,*third;//定义链表节点变量
    first =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间
    second =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间
    third =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间 
    third->next = NULL;
    third->data = 30;
    second->next =third;
    second->data=20;
    first->next = second;
    first->data =10;
    return first;
}

void showNodes(Node *n){
  Node *pn =n;
  while(pn!=NULL){
      printf("node data:%d\n",pn->data);
       pn=pn->next;
       
  }
}
int main() {
    Node *pn =createList();
    showNodes(pn);
    return 0;
}

## 实例2

#include <stdio.h>
#include "stdlib.h"				//提供malloc()和free()
#include "string.h"
#include <stdarg.h>

typedef struct Node{
    char* data;
    struct Node* next;
}Node;

Node* head= NULL;

Node* end = NULL;

struct Node*  AddListTill(char* a )
{
    //创建一个节点
   Node* temp=(Node*)malloc(sizeof(Node));		//此处注意强制类型转换

    //节点数据进行赋值
    temp->data=a;
    temp->next=NULL;

    //连接分两种情况1.一个节点都没有2.已经有节点了，添加到尾巴上
   /* if(NULL==head)
    {

        head=temp;
       // end=temp;
    }
    else
    {
        end->next=temp;
        //	end=temp;			//尾结点应该始终指向最后一个
    }
    end=temp;//尾结点应该始终指向最后一个
*/
    return temp;

}
void showNodeInfo(Node *n){

   while(n!=NULL){
       printf("%s\n",n->data);

       n=n->next;
        
   }

}

Node* anyNode(int count,...){ //利用可变参数动态创建链表
    va_list args;
    int j=0;
    va_start(args,count);
    Node *np[count];
    for(int i=0;i<count;i++){

       np[i]=(Node*)malloc(sizeof(Node));
        np[i]->data=va_arg(args,char*);
        np[i]->next=NULL;
        j++;
    }
    for(int i=0;i<count;i++){
        np[i]->next=np[i+1];
    }
    va_end(args);
    return np[0];
}

int main() {
   // printf("Hello, World!\n");
    /* Node* node =(Node*)malloc(sizeof(Node));
     Node* node1=(Node*)malloc(sizeof(Node));
     Node* node2=(Node*)malloc(sizeof(Node));
     Node* node3=(Node*)malloc(sizeof(Node));
    node = AddListTill("pussy");
    node1=AddListTill("vagina");
    node2=AddListTill("labias");
    node3=AddListTill("clitoris");
    node3->next=NULL;
   node2->next=node3;
   node1->next=node2;
   node->next =node1;*/
    //printf("%s",node);
    Node* node2 =(Node*)malloc(sizeof(Node));
   // node2 =anyNode(3,"pussy","breast","clitoris");
    node2=anyNode(4,"c++","golang","python","java");
    showNodeInfo(node2);

    return 0;
}

结果：
D:\ClionProjects\src\linklist\cmake-build-debug\linklist.exe
c++
golang
python
java
# <a href="https://blog.csdn.net/bufanq/article/details/51567454">C语言实现字符串的查找和替换</a>

# c语言实现替换指定的字符串
int ReplaceStr(char* sSrc, char* sMatchStr, char* sReplaceStr)
{
    int StringLen;
    char caNewString[64];
    char* FindPos;
    FindPos =(char *)strstr(sSrc, sMatchStr);
    if( (!FindPos) || (!sMatchStr) )
        return -1;

    while( FindPos )
    {
        memset(caNewString, 0, sizeof(caNewString));
        StringLen = FindPos - sSrc;
        strncpy(caNewString, sSrc, StringLen);
        strcat(caNewString, sReplaceStr);
        strcat(caNewString, FindPos + strlen(sMatchStr));
        strcpy(sSrc, caNewString);

        FindPos =(char *)strstr(sSrc, sMatchStr);
    }
    free(FindPos);
    return 0;
}


int main() {
    time_t curtime;
    time(&curtime);
    char* date = ctime(&curtime);
    ReplaceStr(date," ",",");
    printf("%s",date);
    return 0;

}

# c语言利用sscanf和sprinf函数巧妙格式化输出当前时间（vscode版本）

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    char * strtime=asctime(p); //这个格式不太好，我们需要对它进行处理
    //printf("time now is %d/%d/%d %d:%d:%d",p->tm_mday,p->tm_mon,p->tm_year,p->tm_hour,p->tm_min,p->tm_sec);
    printf("time now is %d/%d/%d %d:%d:%d\n",p->tm_hour,p->tm_min,p->tm_sec);
    printf("%s",strtime);
    char weekday[10];
    char month[5];
    char day[5];
    int hour,min,sec;
    int year;
    sscanf(strtime,"%s %s %s %d:%d:%d %d",weekday,month,day,&hour,&min,&sec,&year);
    char mytime[100];
    sprintf(mytime,"%s/%s/%d %s %d:%d:%d",day,month,year,weekday,hour,min,sec);
    printf("time :%s",mytime);
    //printf("time :%s/%s/%d %s %d:%d:%d",day,month,year,weekday,hour,min,sec);
    return 0;
}
结果：
time now is 13/56/38 12260032:0:12260032
Wed Dec 09 13:56:38 2020
time :09/Dec/2020 Wed 13:56:38 //这个就是我们需要的结果




