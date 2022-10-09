#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *elements;
    int top;
    int capacity;
};

struct stack initialize();
int is_full(struct stack *stk);
int is_empty(struct stack *stk);
void push(struct stack *stk, int element);
int pop(struct stack *stk);
int peek(struct stack stk);
void display_elements(struct stack stk);

int main()
{
    struct stack stk;
    int elements_size;
    printf("Enter the maximum stack capacity: ");
    scanf("%d", &elements_size);
    stk = initialize(elements_size);
int choice;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("0. To quit\n");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push to stack: ");
            int val;
            scanf("%d", &val);
            push(&stk, val);
            break;
        case 2:
            printf("Performing the pop operation\n");
            int popped = pop(&stk);
            printf("The popped value is: %d", popped);
            break;
        case 3:
            printf("Performing the Peek operation\n");
            int peek_val = peek(stk);
            printf("Peek value is: %d", peek_val);
            break;
        case 4:
            printf("Displaying the stack elements\n");
            display_elements(stk);
            break;
        
        default:
            break;
        }

    } while (choice < 5 && choice > 0);
    return 0;
}

struct stack initialize(int max_size)
{
    struct stack stk;
    stk.capacity = max_size;
    stk.elements = (int*)malloc(max_size * sizeof(int));
    stk.top = -1;
    return stk;
}

int is_full(struct stack *stk)
{
    if((*stk).top == (*stk).capacity - 1)
        return 1;
    else
        return 0;
}

int is_empty(struct stack *stk)
{
    if((*stk).top == -1)
        return 1;
    else
        return 0;
}


void push(struct stack *stk, int element)
{
    if(is_full(stk) == 0)
    {   
        (*stk).top = (*stk).top + 1;
        (*stk).elements[(*stk).top] = element;
    }
    else
    {    
        printf("Stack is full we can't push!");
        return;
    }
}

int pop(struct stack *stk)
{
    int popped = 0;
    if(is_empty(stk) == 0)
    {
        popped = (*stk).elements[(*stk).top];
        (*stk).top = (*stk).top - 1;
        return popped;
    }
    else
    {
        printf("Stack is empty cant pop!");
        return -1;
    }
}

int peek(struct stack stk)
{
    if(is_empty(&stk) == 0)
        return stk.elements[stk.top];
    else
    {
        printf("Stack is empty no elements present");
        return -1;
    }
}

void display_elements(struct stack stk)
{
    if(is_empty(&stk) == 0)
    {
        int i;
        printf("[");
        for(i = stk.top; i >= 0; i--)
        {
            printf("%d ", stk.elements[i]);
        }
        printf("]");
    }
    else
    {
        printf("Stack is empty no elements to display!");
        return;
    }
}