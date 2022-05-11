/* Implement a function that reads an arbitrarily long input from standard input and for each row prints how many words,
 integer numbers, floating-point numbers, and others are to be found. Apply common conventions regarding the definition of the words and 
 numbers. In the other 
category, you should count something like "ana12mere" which is neither word nor number. Also, provide an adequate main() function.*/
#include <stdio.h>

void readtext()
{
    int c;
    int line = 1;
    int word = 0;
    int ints = 0;
    int floats = 0;
    int others = 0;
    int ok = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            printf("on line%d, we have %d words, %d int, %d floating, %d others", word, ints, floats, others);
            line++;
            word = 0;
            ints = 0;
            floats = 0;
            others = 0;
        }
        if (isdigit(c))
        {
            ungetc(c, stdin);
            while ((c = getchar()) != ' ')
            {
                if (!isdigit(c))
                {
                    ok = 0;
                }
            }
            if (ok == 1)
            {
                ints++;
            }
            else
                others++;
            ok = 1;
        }
        if (isalpha(c))
        {
            ungetc(c, stdin);
            while ((c = getchar()) != ' ')
            {
                if (!isalpha(c))
                {
                    ok = 0;
                }
            }
            if (ok == 1)
            {
                word++;
            }
            else
                others++;
            ok = 1;
        }
    }
}

int main()
{
    readtext();
    return 0;
}