#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;
int size;


void initialize();
void display_elements();
void insert_at_end();
void insert_at_beginning();
void insert_before();
void insert_after();
void delete_at_end();
void delete_at_beginning();
void delete_after();
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
    printf("\n4. INSERT BEFORE\n");
    printf("\n5. INSERT AFTER\n");
    printf("\n6. DELETE AT END\n");
    printf("\n7. DELETE AT THE BEGINNING\n");
    printf("\n8. DELETE AFTER\n");
    printf("\n9. REVERSE THE LIST\n");
    printf("\n0. EXIT\n");
    printf("----------\n\n");

    scanf("%d", &option);

    if (option == 1)
        display_elements();
    else if (option == 2) 
        insert_at_beginning();
    else if (option == 3)
        insert_at_end();
    else if (option == 4)
        insert_before();
    else if (option == 5)
        insert_after();
    else if (option == 6)
        delete_at_end();
    else if (option == 7)
        delete_at_beginning();
    else if (option == 8)
        delete_after();
    else if (option == 9)
        reversell();
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

// Getting node details
int node_details(bool before)
{
    int x;
    if (before == true)
    {
        printf("\nEnter the node you want to do operation before: ");
        scanf("%d", &x);
        return x;
    }
    printf("\nEnter the node you want to do operation after: ");
    scanf("%d", &x);
    return x;
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
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        size += 1;
        return;
    }
    Node *new_node = head;
    while(new_node->next != NULL)
    {
        new_node = new_node -> next;
    }
    size += 1;
    new_node ->next = ptr;
    
}

// Inserting before a given node
void insert_before()
{   
    if (head == NULL)
    {
        printf("\nThe list is empt insert data normaly\n");
        insert_at_beginning();
        return;
    }
    int node_data = node_details(true);
    if (node_data == head->data)
    {
        insert_at_beginning();
        return;
    }
    bool check = false;
    Node *ptr = head;
    Node *curr;
    while(ptr->next != NULL)
    {
        curr = ptr;
        ptr = ptr->next;
        if (ptr -> data == node_data)
        {   
            check = true;
            break;
        }
    }
    if (check)
    {
        Node *to_insert;
        to_insert = get_node_data();
        to_insert ->next = ptr;
        curr -> next = to_insert;
        return;
    }
    printf("\nNode not found inserting element at the end\n");
    insert_at_end();
}

// Inserting after a given node
void insert_after()
{
    if (head == NULL)
    {
        printf("\nThe list is empt insert data normaly\n");
        insert_at_beginning();
        return;
    }
    int node_data = node_details(false);
    if (node_data == head->data)
    {
        insert_at_end();
        return;
    }
    bool check;
    Node *ptr = head;
    Node *curr = ptr;
    while(ptr->next != NULL)
    {
        curr = ptr;
        ptr = ptr->next;
        if (ptr -> data == node_data)
        {
            check = true;
            break;
        }
    }
    if (check)
    {
        Node *to_insert;
        to_insert = get_node_data();
        curr = ptr;
        ptr = ptr -> next;
        to_insert ->next = ptr;
        curr -> next = to_insert;
        return;
    }
    printf("\nNode not found inserting element at the end\n");
    insert_at_end();
}

// Deleting the last node from the linked list
void delete_at_end()
{
    if (head == NULL)
    {
        printf("\nLinked List Underflow\n");
        return;
    }
    Node *ptr = head;
    Node *curr;
    while(ptr->next != NULL)
    {
        curr = ptr;
        ptr = ptr->next;
    }

    curr->next = NULL;
    free(ptr);  
}

// Deleting node at the beginning of the list

void delete_at_beginning()
{
    if (head ==NULL)
    {
        printf("\nLinked List Underflow\n");
        return;
    }
    Node *ptr = head;
    head = head->next;
    free(ptr);
}

// Deleting after a given node
void delete_after()
{
    if (head == NULL)
    {
        printf("\nLinked List Underflow\n");
        return;
    }
    bool check;
    Node *ptr = head;
    Node *curr;
    int node_data = node_details(false);
    if(head->next == NULL)
    {
        if(head->data == node_data)
        {
            head = NULL;
            return;
        }

        else
        {
            printf("\nCan't delete node data not found\n");
            return;
        }
    }
    while(ptr->next != NULL)
    {
        curr = ptr;
        ptr = ptr->next;
        if (ptr -> data == node_data)
        {
            check = true;
            break;
        }
    }
    if (check)
    {
        curr = ptr;
        ptr = ptr->next;
        curr -> next = ptr -> next;
        return;
    }
    printf("\nNode not found try again\n");    
}

// Reversing a linked list
void reversell()
{
    if (head == NULL)
    {
        printf("\nLinked List Underflow\n");
        return;
    }
    Node *ptr = head;
    Node *prev = NULL;
    Node *up_next = NULL;

    while(ptr != NULL)
    {
        up_next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = up_next;
    }
    head = prev; 
}
