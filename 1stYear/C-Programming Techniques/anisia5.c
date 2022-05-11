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
