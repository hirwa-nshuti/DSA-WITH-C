#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int length(char *str);
void delete_char(char *str, char del, int len);
void del_char(char*str, char del)

int main()
{
    char str[MAX_SIZE];
    printf("Input a string: ");
    fgets(str, MAX_SIZE, stdin);
    int len = length(str);
    char del;
    printf("Given string is:\n");
    printf("%s", str);
    printf("Enter the character to delete from the string: ");
    scanf("%c", &del);
    printf("After deleting the given character we have:\n");
    delete_char(str, del, len);

    return 0;
}

int length(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len - 1;
}

void delete_char(char *str, char del, int len)
{
    int i, size = len - 1, count = 0;
    char out[MAX_SIZE];

    for (i = 0; i <= size; i++)
    {
        if (str[i] != del)
        {
            out[count] = str[i];
            count++;
        }
    }
    printf("%s", out);
}

void del_char(char* str, char del, int len)
{
}
