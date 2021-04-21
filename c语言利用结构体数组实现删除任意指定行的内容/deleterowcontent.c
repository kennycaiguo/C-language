#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRows(char *filename)
{
    FILE *pf = fopen("test.txt", "r");
    int count = 0;
    char buf[1024] = {0};
    while (fgets(buf, sizeof(buf), pf) != NULL)
    {
        //printf("%s ", buf);
        count++;
    }
    fclose(pf);
    // printf("rows:%d\n", count);
    return count;
}
typedef struct Content
{
    char str[1024];
} Content;
void writeArrTofile(char *filename, Content *pc, int n)
{
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++)
    {
        fputs(pc[i].str, fp);
    }

    fclose(fp);
}
//delete content according the numrow
void testDeleteRow(int numrow)
{
    //get rows count
    int rows = getRows("test.txt");
    //assign space to a dynamic array
    Content *pc = (Content *)malloc(1024 * rows);
    //open file
    FILE *pf = fopen("test.txt", "r");
    char buf[1024] = {0};
    int i = 0;
    //read lines from file and save it in the array
    while (fgets(buf, sizeof(buf), pf) != NULL)
    {
        strcpy(pc[i].str, buf);
        i++;
    }
    /* for (i = 0; i < rows; i++)
    {
        printf("%s\n", pc[i].str);
    } */
    fclose(pf);
    for (i = (numrow - 1); i < rows; i++)
    {

        strcpy(pc[i].str, pc[i + 1].str);
    }
    writeArrTofile("test.txt", pc, rows);
}
int main(int argc, char const *argv[])
{
    /* code */
    /* int rows = getRows("test.txt");
    printf("rows=%d", rows); */
    testDeleteRow(8);

    return 0;
}
