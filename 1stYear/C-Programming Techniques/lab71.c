#include <stdio.h>
char *a0_19[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
                   "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
char *a20_99[20] = {" ", " ", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};

void ang0_19(int n)
{
    // if ((n >= 0) && (n <= 19))//we test it in main so we don t actually need it here but it is helpful if we want to use the function another time
    {
        printf("%s ", a0_19[n]);
    }
}
void ang20_99(int n)
{
    int fd, sd;
    fd = n / 10;
    sd = n % 10;
    printf("%s ", a20_99[fd]);
    if (sd != 0)
    {
        ang0_19(sd);
    }
}
void ang100_999(int n)
{
    int fd;
    int last_two;

    fd = n / 100;
    last_two = n % 100;
    if (n >= 100)
    {
        ang0_19(fd);
        printf(" hundred ");
    }

    if (last_two == 0)
    {
    }
    else
    {
        if (last_two <= 19)
        {
            ang0_19(last_two);
        }
        if (last_two >= 20)
        {
            ang20_99(last_two);
        }
    }
}
void ang1000_9999(int n)
{
    int fd, lastthree;
    fd = n / 1000;
    ang0_19(fd);
    lastthree = n % 1000;
    printf("thousand ");
    if (lastthree == 0)
    {
    }
    else
    {
        ang100_999(lastthree);
    }
}
void ang10000_99999(int n)
{
    int firsttwo, lastthree;
    firsttwo = n / 1000;
    lastthree = n % 1000;

    if ((firsttwo >= 0) && (firsttwo <= 19))
    {
        ang0_19(firsttwo);
        printf("thousand ");
    }
    if ((firsttwo >= 20) && (firsttwo <= 99))
    {
        ang20_99(firsttwo);
        printf("thousand ");
    }
    if (lastthree == 0)
    {
    }
    else
    {
        ang100_999(lastthree);
    }
}
void ang100000_999999(int n)
{
    int firstthree, lastthree;
    firstthree = n / 1000;
    lastthree = n % 1000;
    ang100_999(firstthree);
    printf("thousand ");
    if (lastthree == 0)
    {
    }
    else
    {
        ang100_999(lastthree);
    }
}
int main()
{
    int x;
    while(1) {
    scanf("%d", &x);
    if ((x >= 0) && (x <= 19))
    {
        ang0_19(x);
    }
    if ((x >= 20) && (x <= 99))
    {
        ang20_99(x);
    }
    if ((x >= 100) && (x <= 999))
    {
        ang100_999(x);
    }
    if ((x >= 1000) && (x <= 9999))
    {
        ang1000_9999(x);
    }
    if ((x >= 10000) && (x <= 99999))
    {
        ang10000_99999(x);
    }
    if ((x >= 100000) && (x <= 999999))
    {
        ang100000_999999(x);
    }
    }
}