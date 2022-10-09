#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;
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
    printf("\nLINKED LIST OPERATIONS\n");
    printf("-------------------------\n");
    initialize();
    int option;
select_option:
    printf("\nMENU\n");
    printf("-------\n");
    printf("\n1. DISPLAY CONTENT\n");
    printf("\n2. INSERT AT THE BEGINNING\n");
    printf("\n3. INSERT AT THE END\n");
    printf("\n4. INSERT AT POSITION\n");
    printf("\n5. DELETE AT END\n");
    printf("\n6. DELETE AT THE BEGINNING\n");
    printf("\n7. DELETE AT POSITION\n");
    printf("\n8. REVERSE THE LIST\n");
    printf("\n9. EXIT\n");
    printf("----------\nn");

    scanf("%d", &option);

    if (option == 1)
        display_elements();
    else if (option == 2) 
        insert_at_beginning();
    else if (option == 3)
        insert_at_end();
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
        goto Thanks;
    goto select_option;

Thanks:
    printf("\n!!!!!!!!!Bye!!!!!!!!\n");
    exit(0);
}

// Function to get node input data
Node *get_node_data()
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    printf("\nEnter the data to the node to insert: ");
    scanf("%d", &(ptr -> data));
    return ptr;
}

// Initializing LL
void initialize()
{
    head = NULL;  
}

// Displaying linked list content
void display_elements()
{
    if(head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    Node *ptr = head;
    int i = 1;
    printf("\nPrinting the linked list contents\n");
    while(ptr != NULL)
    {
        printf("\nNode %d:  %d", i, ptr->data);
        i++;
        ptr = ptr->next;
    }

    free(ptr);
}

// inserting node at the beginning of the linked list
void insert_at_beginning()
{
    Node *ptr;
    ptr = get_node_data();
    if (head == NULL)
    {
        head = ptr;
        size += 1;
        return;
    }
    ptr -> next = head;
    head = ptr;
}

// Inserting the node at the end of a linked list
void insert_at_end()
{
    Node *ptr;
    ptr = get_node_data();
    if (head == NULL)
    {
        head = ptr;
        size += 1;
        return;
    }
    Node *new_node = head;
    while(new_node != NULL)
    {
        if (new_node->next == NULL)
        {
            new_node -> next = ptr;
            head = new_node;
            size += 1;
            return;
        }
        new_node = new_node -> next;
    }
    
}

void delete_at_end()
{
    return;
}
void delete_at_beginning()
{
    return;
}
void delete_at_position()
{
    return;
}

void insert_at_position()
{
    return;
}
void reversell()
{
    return;
}
