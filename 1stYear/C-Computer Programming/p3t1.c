/*3. (2p) Implement a function char* reverseVowel(char *s) which takes a string consisting of words, separated by at least one space
 (excepting the first and last word) and returns another string where each of the words starting with vowel are reversed, leaving the 
 other words unchanged. Keep the same amount of spaces between words.
I.e. “Anthony has a lot of apples and oranges” should be yield into “ynohtnA has a lot fo selppa dna segnaro”*/
#include <stdio.h>
#include <string.h>
//char *
void reverseVowel(char *s)
{
    int n = strlen(s);
    int poz = 0;
    char p[n];
    int k;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (strchr("aeoiuAEIOU", s[i]))
            {
                k = i;
                while (s[k] != ' ')
                {
                    k++;
                }
                for (int j = i; j < k; j++)
                {   
                    p[j] = s[k +i- j-1];
                    printf("%c", p[i]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", p[i]);
        }
    }
}
int main()
{
    char *s = "Anthony";
    //has a lot of apples and oranges";
    //char *p =
    reverseVowel(s);
    return 0;
}