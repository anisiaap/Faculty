/********************************************
1. it has to be an array x
2. the length of x has to be finite
3. x[i] must belong to a finite length set
*******************************************/

/********************************************
void back(step){
    foreach pv possible value{            (1)
        if pv is acceptable               (2)
            record pv                     (3)
            if is a solution              (4)
                print solution            (5)
            else back(step+1)             
        erase pv                          (6)
    }
}
*******************************************/

/********************************************
                PERMUTATIONS


WHY CAN IT BE SOLVED WITH BACKTRACKING?
1. it s an array
2. len = n
3. x[i] ={1, 2, ..., n}

(1)    for(pv = 1; pv <= n; pv++)
(2)     int acceptable(pv, step){
    for(i=0; i<step; i++){
        if(x[i]==pv){
            return false
        }
        return true
    }
}
(3) x[step] = pv
(4) if step==n(n-1)
(5) for....print
(6)  x[step] = -1;
*******************************************/

/********************************************
                COMBINATIONS


WHY CAN IT BE SOLVED WITH BACKTRACKING?
1. it s an array
2. len = k
3. x[i] ={1, 2, ..., n}

(1)    for(pv = 1; pv <= n; pv++)
(2)     int acceptable(pv, step){
    for(i=0; i<step; i++){
        if(pv>x[step-1]){
            return true
        }
        return false
    }
}
(3) x[step] = pv
(4) if step==n(n-1)
(5) for....print
(6)  x[step] = -1;
*******************************************/
/*------------------------------------------
    EXEMPLU
avem monezi in buzunar, cum sa le combinam sa aiba suma 10
solutia o sa arate de genul x[i]={ (1, cati de 1 am), (2, cati de 2 am), (5, cati de 5 am deja)}
c1={(v, nr)}
------------------------------------------*/
/********************************************
                MAZE
     drumul, iesirea din labirint at a given end position, given start position
     afisam matricea cu noul drum
     o bordam cu 1 sa nu iesim in memorie


WHY CAN IT BE SOLVED WITH BACKTRACKING?
1. it s an array    A[m][n]
2. len maxim m*n
3. x[i] ={[0,m]*[0,n]}

dx={+0, 0, 1, -1}
dy={+1, -1, 0, 0}
pcx = startx
pcy = starty

(1) for(pv = 0; pv < 4; pv++)
    pcx=pcx+dx[x[pv]];
    pcy=pcy+dy[y[pv]];

(2) A[pcx][pcy]==0    (A[pcx][pcy]< POZITIA PRECEDENTA pt a merge mereu pe o altitudine mai mica harta topografica)
(3) x[step] = pv
    A[pcx][pcy]=step
(4)
if  pcx=endx
    pcy=endy
(5) for....print
(6) A[pcx][pcy]= 0;
    pcx=pcx-dx[x[pv]];
    pcy=pcy-dy[y[pv]];
    
*******************************************/
/*2. The maze problem can be extended to 3D with N levels and places
to go up and down one level. Solve the maze in a 3D box and
print the result in (i, j, k) format where k is the floor level.*/

#include <stdio.h>

struct poz
{
    int i, j, k;
};
typedef struct poz poz_T;

char maze1[1002][1002][1002], maze_min[1002][1002][1002];
int di[] = {0, 0, 0, 0, 1, -1};
int dj[] = {0, 1, 0, -1, 0, 0}; // right, down, left, up, up in layer, down in layer
int dk[] = {1, 0, -1, 0, 0, 0};

int m1, n1, p1, step, steps, start_i, start_j, start_k, ok, min_step;
poz_T poz_arr[1000006];

void Back(char maze[1002][1002][1002], int poz_i, int poz_j, int poz_k)
{
    int i, j, k, pv;

    for (pv = 0; pv < 6; pv++)
    {
        poz_i = poz_i + di[pv];
        poz_j = poz_j + dj[pv];
        poz_k = poz_k + dk[pv];

        if (maze[poz_i][poz_j][poz_k] == '.')
        {

            step++;
            maze[poz_i][poz_j][poz_k] = 'x';
            poz_arr[step].i = poz_i;
            poz_arr[step].j = poz_j;
            poz_arr[step].k = poz_k;

            if ((poz_i == 1 || poz_i == m1 || poz_j == 1 || poz_j == n1 || poz_k == 1 || poz_k == p1) && (poz_i != start_i || poz_j != start_j || poz_k != start_k))
            {
                steps = step;
                if (ok == 0)
                {
                    min_step = steps;
                }
                ok = 1;
                for (i = 1; i <= steps; i++)
                {
                    printf("%d %d %d\n", poz_arr[i].i, poz_arr[i].j, poz_arr[i].k);
                }
                printf("\n");

                for (i = 1; i <= m1; i++)
                {
                    for (j = 1; j <= n1; j++)
                    {
                        for (k = 1; k <= p1; k++)
                        {
                            printf("%c", maze1[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");

                if (steps < min_step)
                {
                    min_step = steps;
                    for (i = 1; i <= m1; i++)
                    {
                        for (j = 1; j <= n1; j++)
                        {
                            for (k = 1; k <= p1; k++)
                            {
                                maze_min[i][j][k] = maze1[i][j][k];
                            }
                        }
                    }
                }
            }

            else
            {
                Back(maze, poz_i, poz_j, poz_k);
            }

            poz_arr[step].i = 0;
            poz_arr[step].j = 0;
            poz_arr[step].k = 0;
            step--;
            maze[poz_i][poz_j][poz_k] = '.';
        }

        poz_i = poz_i - di[pv];
        poz_j = poz_j - dj[pv];
        poz_k = poz_k - dk[pv];
    }
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        printf("Wrong number of arguments\n");
        return -1;
    }

    printf("Give starting coordinates: ");
    scanf("%d %d %d", &start_i, &start_j, &start_k);

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error at opening input file\n");
        return -1;
    }

    // we build a 3D array that represents the maze from the input file (two layers of the 3D array are sepatated by an empty line)
    char c, c2;
    int i = 1, j = 1, k = 1;
    c = fgetc(f);

    while (c != EOF)
    {
        if (c == '\n')
        {
            if (c2 == '\n')
            {
                i++;
            }
            else
            {
                k = 1;
                j++;
            }
        }
        else
        {
            maze1[i][j][k] = c;
            k++;
        }
        c2 = c;
        c = fgetc(f);
    }

    m1 = i;
    n1 = j;
    p1 = k - 1;

    printf("The size of the maze is %dx%dx%d\n", m1, n1, p1);
    printf("The start is at position %d %d %d\n", start_i, start_j, start_k);
    for (i = 1; i <= m1; i++)
    {
        for (j = 1; j <= n1; j++)
        {
            for (k = 1; k <= p1; k++)
            {
                printf("%c", maze1[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

    // we create a border of the matrix
    for (i = 0; i <= m1 + 1; i++)
    {
        for (j = 0; j <= n1 + 1; j++)
        {
            for (k = 0; k <= p1 + 1; k++)
            {
                if (i == 0 || j == 0 || k == 0 || i == m1 + 1 || j == n1 + 1 || k == p1 + 1)
                {
                    maze1[i][j][k] = '#';
                }
            }
        }
    }

    // we find the solutions to the maze, using backtracking
    Back(maze1, start_i, start_j, start_k);

    // we print the shortest path (if there is one)

    if (ok == 0)
    {
        printf("No solution");
        return 0;
    }

    printf("The shortest path is reached in %d steps:\n", min_step);
    for (i = 1; i <= m1; i++)
    {
        for (j = 1; j <= n1; j++)
        {
            for (k = 1; k <= p1; k++)
            {
                printf("%c", maze_min[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

    fclose(f);
    return 0;
}
