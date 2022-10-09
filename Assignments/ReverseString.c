#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

struct String
{
    int length;
    char str[MAX_SIZE];
};

int Length(char *str);
void Swap(char *x, char *y);
struct String get_str();
void reverse_string(struct String *st);
void display_string(struct String st);
int main()
{
    struct String st;
    st = get_str();
    printf("Before reverse Process\n");
    display_string(st);
    printf("After the reverse Process\n");
    reverse_string(&st);
    display_string(st);
    return 0;
}

struct String get_str()
{
    struct String st;
    printf("Input  a string : ");
    fgets(st.str, MAX_SIZE, stdin);
    st.length = Length(st.str);
    return st;
}

int Length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length - 1;
}

void reverse_string(struct String *st)
{
    int i, j;
    for (i = 0, j = (*st).length - 1; i < j; i++, j--)
    {
        Swap(&((*st).str[i]), &((*st).str[j]));
    }
}

void display_string(struct String st)
{
    int i;
    for(i = 0; i < st.length; i++)
        printf("%c", st.str[i]);
    printf("\n");
}

void Swap(char *x, char *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}