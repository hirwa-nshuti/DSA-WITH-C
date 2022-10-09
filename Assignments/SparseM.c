#include <stdio.h>
#include <stdlib.h>

struct Elements
{
    int i;
    int j;
    int val;
};

struct SparseM
{
    int m;
    int n;
    int num;
    struct Elements *ele;
};

// Creating the Sparse Matrix
void CreateM(struct SparseM *spm)
{
    printf("Enter dimensions: ");
    scanf("%d%d", &spm->m, &spm->n);
    printf("Enter Number of non-zero elemets: ");
    scanf("%d", &spm->num);

    spm->ele = (struct Elements *)malloc(spm->num * sizeof(struct Elements));
    printf("Enter all non-Zero elements\n");
    for (int i = 0; i < spm->num; i++)
    {
        scanf("%d%d%d", &spm->ele[i].i, &spm->ele[i].j, &spm->ele[i].val);
    }
}

// Displaying the matrix

void Display(struct SparseM *spm)
{
    int i, j, k = 0;
    for (i = 0; i < spm->m; i++)
    {
        for (j = 0; j < spm->n; j++)
        {
            if (i == spm->ele[k].i && j == spm->ele[k].j)
            {
                printf("%d ", spm->ele[k++].val);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct SparseM sm1;
    CreateM(&sm1);
    Display(&sm1);
    printf("\n");
}