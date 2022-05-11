/*(3p) Implement a function unsigned long countPairsN(unsigned k);
which reads k pairs of byte values x1 and x2 and returns the number of pairs where there is an 
pair of identical nibbles on identical positions.One such pair could be : x1 = 0xBA32 and x2 = 0xCAD1. Handle common exception cases.*/
#include <stdio.h>
#include <stdint.h>
unsigned long countPairsN(unsigned k)
{
    int a, b;
    unsigned x1;
    unsigned x2;
    int ok;
    int nr = 0;
    unsigned maskA, maskB;
    for (int i = 0; i < k; i++)
    {
        if (scanf("%x %x", &a, &b))
        {
            x1 = a;
            x2 = b;
            ok = 0;
            for (int i = 0; i < 15; i = i + 4)
            {
                maskA = (0xF << i) & x1;
                maskB = (0xF << i) & x2;
                if (maskA == maskB)
                {
                    ok = 1;
                }
                printf("%x %x\n", maskA, maskB);
            }
        }
        if (ok == 1)
        {
            nr++;
        }
        else
            ok = 0;
    }
    return nr;
}
int main()
{
    int x = countPairsN(2);
    printf("%d", x);
    return 0;
}