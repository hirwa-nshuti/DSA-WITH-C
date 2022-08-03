#include <stdio.h>
#include <stdlib.h>

int* get_array(int size)
{
    int* arr = (int *)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++)
    {
        printf("Enter the element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    return arr;
}

void traverse(int*arr)
{
    int size = sizeof(*arr);
    printf("size = %d", size);
    printf("[");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]");
}


int search(int *arr, int key)
{
    int size = sizeof(arr);
    printf("%d", size);
    for(int i = 0; i <= size; i++)
    {
        if(arr[i] == key)
            return i;
    } 
    return -1;

}

void insert_at_end(int* arr, int value)
{
    int size = sizeof(arr)/sizeof(arr[0]);
    int* arr2 = (int*)malloc((size+1)*sizeof(int));
    for (int i = 0; i <= size; i++)
    {
        arr2[i] = arr[i];
    }
    arr = NULL;
    arr = arr2;
    arr2 = NULL;
    traverse(arr);
    arr[size+1] = value;
}

void main()
{
    int size, index;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* arr = get_array(size);
    traverse(arr);
    // int searched = 0;
    // printf("Enter the value to search: ");
    // scanf("%d", &index);
    // // searched = search(arr, index);  
    // // printf("Searched value is: %d", searched);
    // // printf("Inserting at the end:\n");
    // // insert_at_end(arr, 4);
    // // traverse(arr);
    free(arr);
}