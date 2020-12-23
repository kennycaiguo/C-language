#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    stud *s;
    s = (stud *)malloc(sizeof(stud));
    strcpy(s->name, "Jackline");
    strcpy(s->gender, "Female");
    strcpy(s->addr, "6 oxford road");
    s->age = 30;
    s->info = showInfo;
    s->info(s);
    if (s != NULL)
    {
        free(s);
        s = NULL;
    }

    return 0;
}
