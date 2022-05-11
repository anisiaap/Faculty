#include <stdio.h>

char maze1[1001][1001], maze2[1001][1001];
int di[] = {0, 1, 0, -1}; // right, down, left, up
int dj[] = {1, 0, -1, 0};
int m1, n1, step, steps;

void back(char maze[1001][1001], int poz_i, int poz_j, int end_i, int end_j)
{
    int i, j, pv;

    for (pv = 0; pv < 4; pv++)
    {
        poz_i = poz_i + di[pv];
        poz_j = poz_j + dj[pv];

        if (maze[poz_i][poz_j] == ' ' || maze[poz_i][poz_j] == 'E')
        {
            if (maze[poz_i][poz_j] == ' ')
            {
                maze[poz_i][poz_j] = '.';
            }
            step++;
            if (poz_i == end_i && poz_j == end_j)
            {
                steps = step;
                for (i = 1; i <= m1; i++)
                {
                    for (j = 1; j <= n1; j++)
                    {
                        maze2[i][j] = maze[i][j];
                    }
                }
            }

            else
            {
                back(maze, poz_i, poz_j, end_i, end_j);
            }

            step--;
            maze[poz_i][poz_j] = ' ';
        }

        poz_i = poz_i - di[pv];
        poz_j = poz_j - dj[pv];
    }
}

int main(int argc, char **argv)
{
    // we read the maze

    if (argc != 3)
    {
        printf("Wrong number of arguments\n");
        return -1;
    }

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error at opening input file\n");
        return -1;
    }
    int c;
    int i = 1, j = 1, is, js, ie, je;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n')
            i++, j = 1;
        else
        {
            maze1[i][j] = c;
            if (maze1[i][j] == 'S')
            {
                is = i;
                js = j;
                maze1[i][j] = ' ';
            }
            if (maze1[i][j] == 'E')
            {
                ie = i;
                je = j;
                maze1[i][j] = ' ';
            }
            j++;
        }
    }

    j--;
    m1 = i;
    n1 = j;
    printf("%d %d\n", is, js);

    printf("The size of the maze is %dx%d\n", m1, n1);
    
    for (i = 1; i <= m1; i++)
    {
        for (j = 1; j <= n1; j++)
        {
            printf("%c", maze1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // bordare
    for (i = 0; i <= m1 + 1; i++)
    {
        maze1[i][0] = '#';
        maze1[i][n1 + 1] = '#';
    }
    for (i = 0; i <= n1 + 1; i++)
    {
        maze1[0][i] = '#';
        maze1[m1 + 1][i] = '#';
    }
    back(maze1, is, js, ie, je);
    // print the new matrix
    printf("The exit is reached in %d steps\n", steps);
    for (i = 1; i <= m1; i++)
    {
        for (j = 1; j <= n1; j++)
        {
            printf("%c", maze2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // print in file
    f = fopen(argv[2], "w");
    if (f == NULL)
    {
        printf("error");
        return 1;
    }
    for (int i = 1; i <= m1; i++)
    {
        for (int j = 1; j <= n1; j++)
        {
            fprintf(f, "%c", maze2[i][j]);
        }
        fprintf(f, "\n");
    }
    return 0;
}