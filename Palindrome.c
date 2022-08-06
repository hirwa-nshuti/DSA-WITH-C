#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int length(char *str);
int is_palindrome(char *str, int length);

int main()
{
    char str[MAX_SIZE];
    printf("Input  a string : ");
    fgets(str, MAX_SIZE, stdin);
    int len = length(str);

    int pal = is_palindrome(str, len);
    if(pal == 1)
        printf("The given string is Palindrome");
    else
        printf("The string is not Palindrome");
    
    return 0;
}

int length(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len-1;
}

int is_palindrome(char *str, int length)
{
    int i, j, flag=1;
    for(i = 0, j=length-1; i < j; i++, j--)
    {
        if(str[i] != str[j])
        {
            flag = 0;
        }
    }

    return flag;
}