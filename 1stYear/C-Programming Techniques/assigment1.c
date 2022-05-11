#include <stdio.h>

int order, mat[1000][1000], start, route[10000], ok, min_route[10000], min_route_sum, min_count, visited[1000];

int st[100], n, k, min = 1e9, sol[100];

int valid(int k)
{
    for (int i = 0; i < k; i++)
        if (st[k] == st[i])
            return 0;
    if (mat[st[k]][st[k - 1]] < 1)
        return 0;
    return 1;
}
void afisare()
{
    int sum = 0;
    for (int i = 0; i < order - 1; i++)
    {
        sum += mat[st[i]][st[i + 1]];
        printf("%d ", st[i]);
    }
    printf("\n");
    if (sum < min)
    {
        min = sum;
        for (int i = 0; i < order; i++)
            sol[i] = st[i];
    }
}

void bt(int k)
{
    for (int i = 0; i < order; i++)
    {
        st[k] = i;
        if (valid(k))
        {

            if (k == order - 1)
                afisare();
            else
                bt(k + 1);
        }
    }
}

int main(int argc, char **argv)
{


    if (argc != 2)
    {
        printf("Wrong number of arguments");
        return -1;
    }

    FILE *f;
    int i, j;

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error at file opening");
        return -1;
    }

    fscanf(f, "%d", &order);

    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            fscanf(f, "%d", &mat[i][j]);
        }
    }

    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Give a number that represents the starting city (0, 1, ..., order_of_mat-1): ");
    scanf("%d", &start);

    st[0] = start;
    bt(1);

    for (i = 0; i <= order; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n%d ", min);

    fclose(f);
    return 0;
}
