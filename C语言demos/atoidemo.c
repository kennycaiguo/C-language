#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char src[]="100";
    char src1[]="100.12";
    int res = atoi(src);
   float fres = atof(src1);
    printf("res= %d\n",res);
    printf("fres= %f",fres);
    return 0;
}
