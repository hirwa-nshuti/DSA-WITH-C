#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int capability;
    int* elements;
    int top;
};

void initialize(struct stack *stk, int size);
int is_full(struct stack *stk);
int is_empty(struct stack *stk);
int pop(struct stack *stk);
void push(struct stack *stk, int data);
int peek(struct stack *stk);
void display_stack(struct stack *stk);

int main()
{

    int stack_max_elements;
    printf("Enter the maximum elements of a stack: ");
    scanf("%d", &stack_max_elements);
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    initialize(s, stack_max_elements);
    push(s, 3);
    push(s, -1);
    int choice;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push to stack: ");
            int val;
            scanf("%d", &val);
            push(s, val);
            break;
        case 2:
            printf("Performing the pop operation\n");
            int popped = pop(s);
            printf("The popped value is: %d", popped);
            break;
        case 3:
            printf("Performing the Peek operation\n");
            int peeked = peek(s);
            printf("Peeked value is: %d", peeked);
            break;
        case 4:
            printf("Displaying the stack elements\n");
            display_stack(s);
            break;
        
        default:
            break;
        }

    } while (choice < 5 && choice > 0);
    
    free(s);
    return 0;
    
}

void initialize(struct stack *stk, int size)
{
    stk -> capability = size;
    stk -> elements = malloc(size * sizeof(int));
    stk -> top = -1;
}

int is_full(struct stack *stk)
{
    if(stk->top == stk -> capability - 1)
        return 1;
    else
        return 0;
}

int is_empty(struct stack *stk)
{
    if(stk -> top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *stk, int data)
{
    if(is_full(stk) == 0)
    {
        stk -> elements[stk->top + 1] = data;
        stk -> top = stk -> top + 1;
    }
    else
    {    printf("The stack is full we can't push other elements");
        exit(EXIT_FAILURE);
    }

}

int pop(struct stack *stk)
{
    int poped = 0;
    if(is_empty(stk) == 0)
    {
        return stk -> elements[stk->top--];
    }
    else
    {    printf("Stack is empty pop operation not possible");
        exit(EXIT_FAILURE);
    }
}

int peek(struct stack *stk)
{
    if(is_empty(stk) == 0)
        return stk->elements[stk->top];
    else
    {    printf("Stack empty.");
        exit(EXIT_FAILURE);
    }
}

void display_stack(struct stack *stk)
{
    if(stk->top != -1)
    {
        int i;
        printf("[");
        for(i = stk->top; i >= 0; i--)
        {
            printf("%d ", stk->elements[i]);
        }
        printf("]");
    }
    else{
        printf("Stack empty");
        exit(EXIT_FAILURE);
}
}
