#include <stdio.h>
typedef struct student //z
{
    char name[20];
    char gender[6];
    int age;
    char addr[100];
    void (*introduce)(char *name); //这里不能放函数，只能放函数指针
    void (*show)(char *name, char *gender, int age);
} Student;
void introduce(char *name)
{
    printf("Hello My Name is %s\n", name);
}

void info(char *name, char *gender, int age)
{
    printf("My Name is %s\n", name);
    printf("I am a %s\n", gender);
    printf("I am %d years old\n", age);
}
int main(int argc, char const *argv[])
{
    Student s = {
        .name = "Jack", .gender = "male", .age = 18, .addr = "3 pawsey road ,kgn5"};
    /*  printf("My name is %s\n", s.name);
    printf("My gender is %s\n", s.gender);
    printf("I am %d years old\n", s.age); */
    s.introduce = introduce; //就结构体内部的函数指针与同名函数关联起来。
    //s.introduce(s.name);     //调用函数
    s.show = info;
    s.show(s.name, s.gender, s.age);
     printf("++++++++++++++++++++++++\n");
    Student *pstu = &s;
    strcpy(pstu[0].name, "Mary");
    pstu[0].age = 30;
    strcpy(pstu[0].gender, "Felmale");
    pstu->show(pstu->name, pstu->gender, pstu->age);
    return 0;
}
