#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "all lower case";
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') // if this Ascii values are between 'a' and 'z'
        {
            printf("%c", s[i] - 32); // offset Ascii values by 32
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

/*
ALL LOWER CASE
*/
