#include <stdio.h>
#include <string.h>
struct Student //z
{
    char name[20];
    char gender[6];
    int age;
    char addr[100];

    void (*show)(char *name, char *gender, int age, char *addr); //这里不能放函数，只能放函数指针
} stu = {"Pauline", "female", 20, "84 orange street"};           //如果要这样子写，struct前面不能加typedef

void toString(char *name, char *gender, int age, char *addr)
{

    printf("================Student info=============\n");
    printf("Name:%s\n", name);
    printf("Gender: %s\n", gender);
    printf("Age : %d\n", age);
    printf("Address: %s\n", addr);
    printf("======================end==================\n");
}
int main(int argc, char const *argv[])
{
    stu.show = toString;
    stu.show(stu.name, stu.gender, stu.age, stu.addr);
    return 0;
}
