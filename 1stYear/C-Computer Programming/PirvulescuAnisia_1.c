/* Implement a function that reads an arbitrarily long input from standard input and for each row prints how many words,
 integer numbers, floating-point numbers, and others are to be found. Apply common conventions regarding the definition of the words and 
 numbers. In the other 
category, you should count something like "ana12mere" which is neither word nor number. Also, provide an adequate main() function.*/
#include <stdio.h>
#include <ctype.h>

void readtext()
{
    int c;
    int line = 1;
    int word = 0;
    int ints = 0;
    int floats = 0;
    int others = 0;
    int ok = 1;
    int fl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            printf("on line%d, we have %d words, %d int, %d floating, %d others\n", line, word, ints, floats, others);
            line++;
            word = 0;
            ints = 0;
            floats = 0;
            fl = 0;
            others = 0;
        }
        if (isdigit(c))
        {
            //ungetc(c, stdin);
            while ((c != ' ') && (c != '\n') && (c != EOF))
            {
                if ((c == '.') && (ok == 1))
                {
                    while (((c = getchar()) != ' ') && (c != '\n') && (c != EOF))
                    {
                        if (!isdigit(c))
                        {
                            ok = 0;
                        }
                    }
                    if (ok == 1)
                    {
                        floats++;
                        fl = 1;
                        break;
                    }
                }
                else if (!isdigit(c))
                {
                    ok = 0;
                }
                c = getchar();
            }
            if ((c == '\n') || (c == EOF))
            {
                ungetc(c, stdin);
            }
            if ((ok == 1) && (fl == 0))
            {
                ints++;
            }
            else if (fl == 0)
                others++;
            ok = 1;
            fl = 0;
        }
        if (isalpha(c))
        {
            //ungetc(c, stdin);
            while ((c != ' ') && (c != '\n') && (c != EOF))
            {
                if (!isalpha(c))
                {
                    ok = 0;
                }
                c = getchar();
            }
            if ((c == '\n') || (c == EOF))
            {
                ungetc(c, stdin);
            }
            if (ok == 1)
            {
                word++;
            }
            else
                others++;
            ok = 1;
        }
        if (!isalnum(c) && (c != '\n') && (c != EOF) && (c != ' ') && (c != '-') && (c != '+'))
        {
            while (((c = getchar()) != ' ') && (c != '\n') && (c != EOF))
            {
            }
            others++;
            if ((c == '\n') || (c == EOF))
            {
                ungetc(c, stdin);
            }
            ok = 1;
        }
    }
    if (c == EOF)
    {
        printf("on line%d, we have %d words, %d int, %d floating, %d others\n", line, word, ints, floats, others);
    }
}

int main()
{
    readtext();
    return 0;
}