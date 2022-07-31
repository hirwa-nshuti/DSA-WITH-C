#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int Length(char *str);
void reverse(char *str, int length);
void Swap(char *x, char *y);


void main()
{
    char str[MAX_SIZE];
    printf("Input  a string : ");
    fgets(str, MAX_SIZE, stdin);
    int length = Length(str);

    printf("Original string is: %s\n", str);
    reverse(str, length);
    printf("Reversed string is: %s\n", str);
}


int Length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length - 1;
}

void reverse(char *str, int length)
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        Swap(&str[i], &str[j]);
    }
}

void Swap(char *x, char *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}