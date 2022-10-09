#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y);
void Ascend(int *arr, int size);
void Descending(int *arr, int size);
void display_arr(int *arr, int size);
int *get_array(int size);

void main()
{
    int size = 0;
    int *arr;
    printf("Getting array elements: \nEnter the size of array: ");
    scanf("%d", &size);
    arr = get_array(size);
    printf("Before ascending order\n");
    display_arr(arr, size);
    printf("Ordering element in ascending order\n");
    Ascend(arr, size);
    display_arr(arr, size);

    printf("Descending Sorting\n");
    Descending(arr, size);
    display_arr(arr, size);
    free(arr);
}

void Ascend(int *arr, int size)
{
    int flag = 1;
    for (int i = 0; i < size - 1 && flag == 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            flag = 0;
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
    }
}

void Descending(int *arr, int size)
{
    int flag = 1;
    for (int i = 0; i < size - 1 && flag == 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            flag = 0;
            if (arr[j] < arr[j + 1])
            {
                Swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
    }   
}

int *get_array(int size)
{
    int *arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the [%d]th element: ", i);
        scanf("%d", &arr[i]);
    }

    return arr;
}

void display_arr(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void Swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

