#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *first;


struct Node * createnode()
{
    struct Node* new_node;
    int no;
    printf("\Enter the info for new node: ");
    scanf("%d", &no);
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = no;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}

struct Node* insert_at_end(struct Node* curr_node, struct Node* new_node)
{
    if(curr_node != NULL)
    {
        struct Node* tp = curr_node;
        while(tp->next != NULL)
            tp = tp -> next;
        tp -> next = new_node;
        new_node ->prev = tp;
        return curr_node;

    }
    else
    {
        curr_node = new_node;
        return curr_node;
    }
}

