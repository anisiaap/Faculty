/*3. (2p) Implement a function char* extractPrefix(char *s1, char *s2) which takes two strings and returns another string consisting 
of the longest common prefix of the two initial strings
I.e. char s1[]=“palindrome”; char s2[]=”palisade”; should yield “pal”*/
#include <stdio.h>
#include <string.h>
char *extractPrefix(char *s1, char *s2)
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
    char new[n];
    int i = 0;
    while (s1[i] == s2[i])
    {
        new[i] = s1[i];
        i++;
    }
    /*for (int j = 0; j < i; j++)
    {
        printf("%c", new[j]);
    }*/
    new[i] = '\0';
    return new;
}
int main()
{
    char s1[] = "palindrome";
    char s2[] = "palisade";
    char new[strlen(s1)];
    strcpy(new, extractPrefix(s1, s2));
    // for (int j = 0; j < strlen(new); j++)
    // {
    //     printf("%c", new[j]);
    // }
    return 0;
}