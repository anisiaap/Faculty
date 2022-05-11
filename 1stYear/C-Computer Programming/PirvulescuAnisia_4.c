/*4) Implement a program that reads data from a file, specified as a command-line argument, having the following format:

username, hh,  mm

where the fields are separated by a comma and might have an arbitrary number of spaces in between. A line has a maximum of 100 characters.

Print the data from the file in descending order of their last login time (hh, mm), breaking ties (when the last login time is the same) by username.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LN
{
    char *username;
    int hh;
    int mm;
    double sec;
};

typedef struct LN line_T;
int func(char *line)
{
    //int n = 0;
    int i = 0;
    while ((line[i] != ',') && (line[i] != ' '))
    {
        i++;
    }
    return i;
}
int hour(char *line)
{
    int i = 0;
    int hh = 0;
    while (line[i] != ',')
    {
        i++;
    }
    i++;
    while (line[i] == ' ')
    {
        i++;
    }
    hh = (line[i] - '0') * 10 + (line[i + 1] - '0');
    return hh;
}
int minutes(char *line)
{
    int i = 0;
    int mm = 0;
    while (line[i] != ',')
    {
        i++;
    }
    i++;
    while (line[i] != ',')
    {
        i++;
    }
    i++;

    while (line[i] == ' ')
    {
        i++;
    }

    mm = (line[i] - '0') * 10 + (line[i + 1] - '0');
    return mm;
}

int mycmp(const void *row1, const void *row2)
{
    line_T *roW1, *roW2;
    roW1 = (line_T *)row1;
    roW2 = (line_T *)row2;
    if (roW1->hh != roW2->hh)
    {
        return roW2->hh - roW1->hh;
    }
    else if (roW1->mm != roW2->mm)
    {
        return roW2->mm - roW1->mm;
    }
    else
        return strcmp(roW2->username, roW1->username);
}

int main(int argc, char *argv[])
{

    char line[100];
    int nrline = 0;
    line_T *rows = NULL, *aux2;
    if (argc != 2)
    {
        return -1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        return -1;
    }
    while (fgets(line, 100, f))
    {
        if (line[strlen(line) - 1] == '\n')
        {

            aux2 = realloc(rows, (nrline + 1) * sizeof(line_T));
            if (!aux2)
            {
                return -1;
            }
            rows = aux2;
            int n = func(line);

            rows[nrline].username = strndup(line, n);
            int hh = hour(line);
            rows[nrline].hh = hh;
            int mm = minutes(line);
            rows[nrline].mm = mm;
            //printf("%.2f\n", sec);
            nrline++;
        }
    }

    aux2 = realloc(rows, (nrline + 1) * sizeof(line_T));
    if (!aux2)
    {
        return -1;
    }
    rows = aux2;
    int n = func(line);

    rows[nrline].username = strndup(line, n);
    int hh = hour(line);
    rows[nrline].hh = hh;
    int mm = minutes(line);
    rows[nrline].mm = mm;

    nrline++;

    qsort(rows, nrline, sizeof(line_T), mycmp);

    for (int i = 0; i < nrline; i++)
        printf("%s, %d, %d\n", rows[i].username, rows[i].hh, rows[i].mm);

    fclose(f);
    return 0;
}