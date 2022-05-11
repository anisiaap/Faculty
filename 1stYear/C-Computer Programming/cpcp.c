/*4) Implement a program that reads form a file, passed as command-line argument, a set of values (on individual lines) with the format:
name, nol, no2, noN
where the name might have up to 100 characters, followed by an arbitrary number of integer values. All the fields are separated by
comma characters.
Sort the records by the average of the values, breaking ties lexicographically by name.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line
{
    char name[100];
    int *arr;
    float avg;
    int nrnr;
};
typedef struct line line_T;

int mycmp(const void *roW1, const void *roW2)
{
    line_T *row1, *row2;
    row1 = (line_T *)roW1;
    row2 = (line_T *)roW2;
    if (row1->avg != row2->avg)
    {
        return row1->avg - row2->avg;
    }
    else
        return strcmp(row1->name, row2->name);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        return -1;
    }
    int namei = 0, line_nr = 0, *aux2, countnr = 0, x, nrnr;
    char c;
    line_T *line_arr = NULL, *aux;
    c = fgetc(f);
    while (c != EOF)
    {
        namei = 0;
        countnr = 0;
        aux = realloc(line_arr, (line_nr + 1) * sizeof(line_T));
        if (aux == NULL)
        {
            free(line_arr);
            return -69;
        }
        line_arr = aux;

        while (c != ',')
        {

            line_arr[line_nr].name[namei] = c;
            namei++;
            c = fgetc(f);
        }
        int sum = 0;
        while (fscanf(f, "%d,", &x) == 1)
        {
            aux2 = realloc(line_arr[line_nr].arr, (countnr + 1) * sizeof(int));
            if (!aux2)
            {
                free(aux2);
                return -6969;
            }
            line_arr[line_nr].arr = aux2;
            line_arr[line_nr].arr[countnr] = x;
            countnr++;
            sum = sum + x;
        }
        line_arr[line_nr].avg = (float)sum / countnr;
        c = fgetc(f);
        for (int i = 0; i < namei; i++)
        {
            printf("%c", line_arr[line_nr].name[i]);
        }
        //printf("\n");
        for (int i = 0; i < countnr; i++)
        {
            printf(" %d ", line_arr[line_nr].arr[i]);
        }
        printf("\n");
        line_nr++;
        namei = 0;
        nrnr = countnr;
        countnr = 0;
    }
    qsort(line_arr, line_nr, sizeof(line_T), mycmp);
    for (int i = 0; i < line_nr; i++)
    {
        printf("%s", line_arr[i].name);
        for (int j = 0; j < line_arr[i].nrnr;j++){
            printf(" %d ", line_arr[i].arr[j]);
        }
        printf("\n");
    }
   
        return 0;
}