ho#include <stdio.h>

int st[100], k, sol, ok = 1;

int valid(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (st[k] == st[i])
            return 0;
        if (abs(st[k] - st[i]) == k - i)
            return 0;
    }
    return 1;
}
void afisare()
{
    for (int i = 1; i <= 8; i++)
        printf("%d ", st[i]);
    printf("\n");
}

void bt(int k)
{
    for (int i = 1; i <= 8; i++)
    {
        st[k] = i;
        if (valid(k))
        {

            if (k == 8)
            {
                afisare();
                sol++;
            }
            else
                bt(k + 1);
        }
    }
}
int main()
{

    bt(1);
}
