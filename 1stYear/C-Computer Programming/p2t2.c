/*2. (3p) Implement a function unsigned long subSeq(unsigned k); which reads k unsigned numbers and returns the length of the longest 
sub-sequence of numbers having the same number of bits of 1 in their internal representation.
I.e. Fork = 10 and the sequence being 0x29, 0x30, 0x11, 0x6D, 0x1C, 0x61, 0x68, 0x74, 0x07, 0x86 the result should be 3 because there is a 
sub-sequence of three adjacent numbers having exactly three bits of 1 (0x1C, 0x61, 0x68)*/
#include <stdio.h>
unsigned long subSeq(unsigned k)
{
    unsigned x;
    int count = 0;
    int new = 0;
    int old = 0;
    //int len = 0;
    int lenN = 0;
    int lenO = 0;
    for (int j = 0; j < k; j++)
    {
        //int i = 0;
        old = new;
        if (scanf("%x", &x))
        {

            for (int i = 0; i < 32; i++)
            {
                if (x & (1 << i))
                {
                    count++;
                }
            }
            new = count;
            if (new == old)
            {
                lenN++;
            }
            else
                lenN = 0;
        }
        count = 0;
        if (lenN > lenO)
        {
            lenO = lenN;
        }
    }
    return lenO;
}
int main()
{
    int x = subSeq(10);
    printf("%d", x);
    return 0;
}