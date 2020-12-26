#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("letters.txt", "r");
    for (int i = 0; i <= 26; ++i)
    {

        int a = fgetc(f);
        printf("%c", a);
    }

    fclose(f);
    f = NULL;
    return 0;
}
