#include <stdio.h>

struct Sub{
    
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("no file to open");
        return 1;
    }
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("can not open file");
        return 2;
    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        ungetc(c, f);

    }
    fclose(f);
    for (int i = 0; i < 256; i++)
    {
        if (ap[i])
            printf("%c : %d\n", i, ap[i]);
    }

    return 0;
}