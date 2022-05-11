/*3. (2p) Implement a function char* extractSufic(char *s1, char *s2) which takes
 two strings and returns another string consisting of the longest common suffix of the two initial
  strings
I.e. char s1[]=“savanah”; char s2[]=”montanah”; should yield “nah”*/
#include <stdio.h>
#include <string.h>

void extractSufic(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int n;

    if (n1 > n2)
    {
        n = n2;
    }
    else
        n = n1;
    int j = 0;
    //int i = n-1;
    char new[n];
    while (s1[n1] == s2[n2])
    {
        new[j] = s1[n1];
        j++;
        n1--;
        n2--;
    }
    new[j] = '\0';
    
    char new1[n];
    for (int i = 0; i < j; i++)
    {
        printf("%c", new[i]);
    }
    printf("\n");
    n = strlen(new);
    for (int i = 0; i < j; i++)
    {
        new1[i] = new[j - i - 1];
    }
    for (int i = 0; i < j; i++)
    {
        printf("%c", new1[i]);
    }

}

int main()
{
    char s1[] = "savanah";
    char s2[] = "montanah";
    extractSufic(s1, s2);
    return 0;
}