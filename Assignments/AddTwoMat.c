#include <stdio.h>
#include <stdlib.h>

int **get_inputs(int size)
{
    int **arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            printf("Enter the [%d][%d]th element: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}

void display_Mat(int **arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int **addTwoMat(int **arr1, int **arr2, int size)
{
    int **out = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        out[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            out[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return out;
}

void main()
{
    int s = 0;
    printf("Enter the size of Matrix[x][x]: ");
    scanf("%d", &s);
    printf("Enter the elements of the first Matrix\n");
    int **arr1 = get_inputs(s);
    printf("Enter the elements of the second Matrix\n");
    int **arr2 = get_inputs(s);
    printf("First Matrix is \n");
    display_Mat(arr1, s);

    printf("Second Matrix is \n");
    display_Mat(arr2, s);

    printf("Adding Two matrices result is: \n");
    int **arr = addTwoMat(arr1, arr2, s);
    display_Mat(arr, s);
    free(arr1);
    free(arr2);
    free(arr);
}