#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Songs
{
    unsigned year;
    char name[20];
    char autor[20];
};

struct Songs *data2;
int c = 1;

unsigned sint(char *s)
{
    return s[3] + 10 * s[2] + 100 * s[1] + 1000 * s[0];
}

void model(char s[])
{
    char *p;

    if (s[0] == '"')
        p = strtok(s + 1, "\"");
    else
        p = strtok(s, ",");
    strcpy(data2[c].name, p);
    printf("%s ", data2[c].name);
    p = strtok(NULL, ",");
    strcpy(data2[c].autor, p);
    printf("%s ", data2[c].autor);
    p = strtok(NULL, ",");
    data2[c].year = atoi(p);
    printf("%u \n", data2[c].year);
    c++;
}

char buf[500];
int main(int argc, char *argv[])
{

    FILE *f;
    f = fopen(argv[1], "r");
    //f = fopen("rock.csv", "r");
    if (f == NULL)
        printf("error");
    else
    {
        int i = 0;
        while (fgets(buf, 500, f))
        {
            //printf("%s", buf);
            //model(buf);
            i++;
        }
        fclose(f);
        f = fopen(argv[1], "r");
        data2 = (struct Songs *)malloc(sizeof(struct Songs) * i);
        while (fgets(buf, 500, f))
        {
            //printf("%s", buf);
            model(buf);
        }
    }
    return 0;
}