/*2) Implement a function that receives two uint64_t values and sets onto 0 all the bytes from the second argument which are
 found among the bytes of the first argument, regardless of the order, returning the result. Also, provide an adequate main() function.*/
#include <stdio.h>
#include <stdint.h>
uint64_t func(uint64_t a, uint64_t b)
{
    //uint64_t new;
    uint64_t mask = 0xFF;
    uint64_t byteA, byteB;
    for (int i = 0; i < 64; i = i + 8)
    {
        byteA = (a & (mask << i)) >> i;
        //printf("%llx\n", byteA);
        for (int j = 0; j < 64; j = j + 8)
        {
            byteB = (b & (mask << j)) >> j;

            if (byteB == byteA)
            {
                b = b & (~(mask << j));
                //printf("%llx\n", b);
            }
        }
    }

    return b;
}

int main()
{
    uint64_t x = func(0X20A1B4, 0xA1B2C3D4A1FFC3D4);
    printf("%llx", x);
    return 0;
}
