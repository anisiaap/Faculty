#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song
{
    char name[100];
    char author[100];
    int year;
    char fn[200];
    int i1;
    int i2;
    int i3;
    int i4;
} SONG;
int songlength = 0;
SONG songs[2500];
void bubblesort(SONG v[], int songlength)
{
    int ok;
    SONG aux;
    do
    {
        ok = 1;
        for (int i = 0; i < songlength; i++)
        {
            if (v[i].year < v[i + 1].year)
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = 0;
            }
        }
    } while (ok == 0);
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error no of args\n");
        exit(2);
    }

    char filename[100];
    strcpy(filename, argv[1]);

    // int year = atoi(argv[2]);

    // printf("Read from args: f=%s, y=%d\n", filename, year);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("ERROR FILE!\n");
        exit(2);
    }

    while (!feof(file))
    {
        char *line = (char *)malloc(1000);
        // int index = 0;
        // int c;
        if (line == NULL)
        {
            printf("ERROR malloc");
            exit(2);
        }

        if (fgets(line, 1000, file) == NULL)
        {
            continue;
        }

        line[strlen(line) - 1] = 0;
        int index = 0;
        int ok = 0, j = 0;
        SONG aux;
        char buf[100];
        memset(buf, 0, 100);
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '"')
            {
                if (ok == 0)
                {           // first "
                    ok = 1; // now we are inside a " " field
                }
                else
                    ok = 0;
            }
            else if (line[i] == ',')
            {
                if (ok == 0)
                {
                    switch (index)
                    {
                    case 0:
                        strcpy(aux.name, buf);
                        break;
                    case 1:
                        strcpy(aux.author, buf);
                        break;
                    case 2:
                        aux.year = atoi(buf);
                        break;
                    case 3:
                        strcpy(aux.fn, buf);
                        break;
                    case 4:
                        aux.i1 = atoi(buf);
                        break;
                    case 5:
                        aux.i2 = atoi(buf);
                        break;
                    case 6:
                        aux.i3 = atoi(buf);
                        break;
                    case 7:
                        aux.i4 = atoi(buf);
                        break;
                    }
                    index++;
                    memset(buf, 0, 100);
                    j = 0;
                }

                else
                {
                    buf[j++] = line[i];
                }
            }
            else
            {
                buf[j++] = line[i];
            }
        }
        songs[songlength++] = aux;
        free(line);
    }

    fclose(file);
    bubblesort(songs, songlength);
    for (int i = 0; i < songlength; i++)
    {
        // if (year == songs[i].year)

        printf("%d - %s - %d\n", i, songs[i].name, songs[i].year);
    }

    return 1;
}
