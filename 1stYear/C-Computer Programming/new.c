/*3. (2p) Implement a function char* duplicateFirstWord(char *s) which takes a string consisting of words, separated by at least one
 space (excepting the first and last word) and returns another string in which you have replaced all the words starting with a vowel with the
 first word form original string
I.e. “anna has apples and some oranges” should be yield “has anna anna some anna”*/
#include <stdio.h>
#include <string.h>
//char *
void duplicateFirstWord(char *s)
{
    int n = strlen(s);
    char new1[n];
    char new[n];
    char cuv[n];
    int dim = 0;
    while (s[dim] != ' ' && s[dim] != '\0')
    {
        cuv[dim] = s[dim];
        dim++;
    }
    strcpy(new1, s + dim);
    n = strlen(new1);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (new1[i] == ' ' && strchr("aeiouAEIOU", new1[i + 1]))
        {
            i++;
            while (new1[i] != ' ')
            {
                i++;
            }
            
        }
        else{
            while (new1[i] != ' ')
            {
                new[count] = new1[i];
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%c", new[i]);
    }

    //return new;
}

int main()
{
    char *s = "anna has apples and some oranges";
    char new[strlen(s)];
    //strcpy(new, 
    duplicateFirstWord(s);
    return 0;
}