/*2.(3p)Implement a function unsigned long countPairs(unsigned k);   
which reads k pairs of byte values(x1, x2) and returns the number of pairs where x1 is
 equal with value of x2 with the bits in opposite order.One such pair could be : x1 = 0xB3 and x2 = 0xCD. Handle common exception cases.*/
#include <stdio.h>
#include <stdint.h>

unsigned long countPairs(unsigned k)
{
    unsigned a, b;
    uint8_t x1;
    uint8_t x2;
    int p = 0;
    //uint8_t mask = 0xFF;
    uint8_t new = 0;
    for (int i = 0; i < k; i++)
    {
        if (scanf("%x %x", &a, &b))
        {
            x1 = a;
            x2 = b;
            //printf("%x, %x\n", x1, x2);

            for (int i = 0; i < 8; i++)
            { //0000 0011
                new = (((x2 & (1 << i))>>i)<<(7-i)) | new;
                //printf("%x\n", new);
            }
            if(new==x1){
                p++;
            }
        }
    }
    return p;
}
int main()
{
    int x = countPairs(2);
    printf("%d", x);
    return 0;
}
