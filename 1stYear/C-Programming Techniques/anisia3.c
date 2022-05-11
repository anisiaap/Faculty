// I did it in two ways, first is when we can have multiple coins with the same value like 1 2 1 2(they can simply repeat)
//  the second one is when we have only once the value of the coins but also the nr of appearances (1,2) the coin with value 1 is 2 times in my pocket
#include <stdio.h>

int st[100], k, ok = 1;
int x, n, arr[100];

int valid(int k)
{
    for (int i = 1; i < k; i++)
        if (st[k] == st[i])
            return 0;
    return 1;
}

int sol(int k)
{
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += arr[st[i]];
    return sum;
}

void afisare(int k)
{
    for (int i = 1; i <= k; i++)
        printf("%d ", arr[st[i]]);
    printf("\n");
}

void bt(int k)
{
    for (int i = 0; i < n; i++)
    {
        st[k] = i;
        if (valid(k))
        {
            if (sol(k) == x)
                afisare(k);
            else
                bt(k + 1);
        }
    }
}

int main()
{
    scanf("%d%d", &x, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bt(1);
    return 0;
}

// 100 5 25 50 75 50 100
/*
#include<stdio.h>

int n , S, v[10], x[10], c[100];

void Afis(int k)
{

    for(int i = 1 ; i <= k ; i ++)
        printf("%d ", x[i]);
    printf("\n");
}

void back(int k, int sum)
{
    if(k <= n) {
        int j = 0;
        if((S - sum) / v[k] < c[k])
            j = (S - sum) / v[k];
        else
            j = c[k];
        for(int i = 1 ; i <= j; i ++)
        {
            x[k] = i;
            if(sum + x[k] * v[k] == S)
                Afis(k);
            else
                back(k + 1 , sum + x[k] * v[k]);
        }
    }
}

int main()
{

    scanf("%d%d", &n, &S);
    for(int i = 1 ; i <= n ; ++i)
        scanf("%d", &v[i]);
    for(int i = 1 ; i <= n ; ++i)
        scanf("%d", &c[i]);
    back(1, 0);
    return 0;
}
*/