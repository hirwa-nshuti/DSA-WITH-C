#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *curr = NULL;
int size;
void initialize();
void display_elements();
void delete_at_end();
void delete_at_beginning();
void delete_at_position();
void insert_at_end();
void insert_at_beginning();
void insert_at_position();
void reversell();
void main()
{
    int option;
select_option:
    printf("\n1. INSERT AT THE END\n");
    printf("\n2. DISPLAY CONTENT\n");
    printf("\n3. INSERT AT BEGINNING\n");
    printf("\n4. INSERT AT POSITION\n");
    printf("\n5. DELETE AT END\n");
    printf("\n6. DELETE AT THE BEGINNING\n");
    printf("\n7. DELETE AT POSITION\n");
    printf("\n8. REVERSE THE LIST\n");
    printf("\n9. EXIT\n");
    printf("-------------\n");

        scanf("%d", &option);
    if (option == 1)
        goto select_option;
    else if (option == 2) 
        goto select_option;
    else if (option == 3)
        goto select_option;
    else if (option == 4)
        goto select_option;
    else if (option == 5)
        goto select_option;
    else if (option == 6)
        goto select_option;
    else if (option == 7)
        goto select_option;
    else if (option == 8)
        goto select_option;
    else
        exit(0);
    goto select_option;
}