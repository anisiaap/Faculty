#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    char *s = NULL, buf[50], *aux = NULL;
    int nrbuf = 0;
    if (argc < 2)
    {
        printf("no files to open");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        if ((f = fopen(argv[i], "r")) != NULL)
        {
            while (fgets(buf, 50, f) != NULL)
            {
                nrbuf++;
                aux = realloc(s, 20 * nrbuf * sizeof(char) + 1);
                if (aux == NULL)
                {
                    free(s);
                    printf("error");
                    return 2;
                }

                s = aux;
                strcat(s, buf);
            }

            if ((f = freopen(argv[i], "w", f)) == NULL)
            {
                printf("error");
                return 3;
            }

            fprintf(f, "%s", s);

            s = NULL;
            free(s);
            fclose(f);
        }

        else
        {
            printf("error");
            return 3;
        }
    }
    return 0;
}