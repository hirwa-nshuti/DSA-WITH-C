#include <stdio.h>
#include <stdlib.h>

#define MAX_Size 100

int length(char* str);
void merge(char *st1, char *str2, char *str3);

int main()
{
    char str1[MAX_Size], str2[MAX_Size], str3[MAX_Size];
    printf("Enter the first string: ");
    fgets(str1, MAX_Size, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_Size, stdin);
    merge(str1, str2, str3);
    printf("After The merge the output string is:\n");
    printf("%s", str3);
    return 0;
}

int length(char *str)
{
    int len = 0;
    while(str[len] != '\0')
        len++;
    return len;
}

void merge(char *str1, char *str2, char *str3)
{
    int i, j=0, l1 = length(str1), l2 = length(str2);
    if(l1 == l2)
    {
        for(i = 0; i < l1 - 1; i++)
        {
            str3[j++] = str1[i];
            str3[j++] = str2[i];
        }
    }
}