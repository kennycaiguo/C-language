#include <stdio.h>
#include <string.h>
typedef struct Student //z
{
    char name[20];
    char gender[6];
    int age;
    char addr[100];

    void (*show)(char *name, char *gender, int age, char *addr); //这里不能放函数，只能放函数指针
    void (*info)(struct Student *s);
} stud;

void toString(char *name, char *gender, int age, char *addr)
{

    printf("================Student info=============\n");
    printf("Name:%s\n", name);
    printf("Gender: %s\n", gender);
    printf("Age : %d\n", age);
    printf("Address: %s\n", addr);
    printf("======================end==================\n");
}
void showInfo(stud *s)
{
    printf("================Student info=============\n");
    printf("Name:%s\n", s->name);
    printf("Gender: %s\n", s->gender);
    printf("Age : %d\n", s->age);
    printf("Address: %s\n", s->addr);
    printf("======================end==================\n");
}
int main(int argc, char const *argv[])
{
    stud stu[2] = {{"Mike", "Male", 22, "23 beckford street"},
                   {"Mary", "Female", 23, "20 duke street"}}; //初始化一个学生数组
    stu[0].show = toString;
    stu[0].show(stu[0].name, stu[0].gender, stu[0].age, stu[0].addr);
    printf("===============================================");
    stu[1].info = showInfo;
    stu[1].info(&stu[1]);
    return 0;
}
