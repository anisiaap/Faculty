#include <stdio.h>



int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("no file to open");
        return 1;
    }
    FILE *f1, *f;
    f = fopen(argv[1], "r");
    f1= fopen(argv[2], "w");

    if (f == NULL)
    {
        printf("can not open file");
        return 2;
    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if(c=='\n'){
            fprintf(f1, "\r\n");
        }
        else
            fprintf(f1, "%c", c);
    }
    fclose(f);
    fclose(f1);
    return 0;
}