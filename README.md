# C-language
# <a href="https://zhuanlan.zhihu.com/p/84828775">c语言操作mysql数据库</a>
# <a href="https://www.jianshu.com/p/5b80aa05199a">c语言操作mysql数据库</a>
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
