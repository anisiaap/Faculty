#include <stdio.h>

int a[16][16], n, m, i, j, k, ic, jc;
int ok = 0;

int isFull()
{
    for (i = 2; i <= n + 1; i++)
        for (j = 2; j <= m + 1; j++)
            if (a[i][j] == 0)
                return 0;
    return 1;
}

void print()
{
    for (i = 2; i <= n + 1; i++)
    {
        for (j = 2; j <= m + 1; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void bt(int i, int j)
{
    if (a[i][j] == 0)
    {
        a[i][j] = ++k;
        if (isFull())
        {
            if (ok == 0)
                print();
            ok = 1;
        }
        else
        {
            bt(i - 1, j - 2);
            bt(i - 2, j - 1);
            bt(i - 2, j + 1);
            bt(i - 1, j + 2);
            bt(i + 1, j + 2);
            bt(i + 2, j + 1);
            bt(i + 2, j - 1);
            bt(i + 1, j - 2);
        }
        a[i][j] = 0;
        k--;
    }
}
int main()
{
    n = 8;
    m = 8;
    scanf("%d%d", &ic, &jc);

    for (i = 0; i <= n + 3; i++)
    {
        a[i][0] = -1;
        a[i][1] = -1;
        a[i][m + 2] = -1;
        a[i][m + 3] = -1;
    }
    for (i = 0; i <= m + 3; i++)
    {
        a[0][i] = -1;
        a[1][i] = -1;
        a[n + 2][i] = -1;
        a[n + 3][i] = -1;
    }

    bt(ic + 1, jc + 1);
}
