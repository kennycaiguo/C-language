#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("letters.txt", "a");
    /* for (char i = 'a'; i <= 'z'; ++i)
    {

        //fputc(i, f);//i 也可以是整数，如97则写入a
        fputc(i, stdout); //注意将文件指针改为stdout就可以往屏幕输出
    } */
    for (int i = 65; i <= 90; ++i)
    {

        //fputc(i, f);//i 也可以是整数，如97则写入a
        fputc(i, f); //注意将文件指针改为stdout就可以往屏幕输出
    }
    fclose(f);
    f = NULL;
    return 0;
}
