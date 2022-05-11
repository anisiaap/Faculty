/*(2p) Implement a function char* removeFirstWord(char *s) which takes a string consisting of words, separated by at least one space
 (excepting the first and last word) and returns another string in which you have removed all the occurrences of the first word from the
  original string.
I.e. “around 
what goes around, comes around” should be yield into “what goes, comes”*/
#include <stdio.h>
#include <string.h>
//char *
void removeFirstWord(char *s)
{
    int n = strlen(s);
    int j = 0;
    int dim = 0;
    char cuv[n], new[n];
    while (s[dim] != ' ')
    {
        cuv[dim] = s[dim];
        dim++;
    }
    /*for (int j = 0; j<i;j++){
        printf("%c", cuv[j]);
    }*/
    strcpy(s, s + dim + 1);
    printf("%c", s[0]);
    int k = 0;
    n = strlen(s);
    int count;
    /*for (int i = 0; i < n; i++)
    {
        count = i;
        while (s[i] == cuv[j])
        {
            k++;
            i++;
            j++;
        }
        if(k==dim){
            strcpy(s + (count - k), s + k);
        }
        //j++;
        k = 0;
        n = strlen(s);
    }*/

    
}
int main()
{
    char *s = "around what goes around, comes around";
    removeFirstWord(s);
    return 0;
}