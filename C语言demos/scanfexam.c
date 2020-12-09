#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    char * strtime=asctime(p);
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
