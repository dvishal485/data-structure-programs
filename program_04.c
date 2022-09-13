#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, k, delRow;
    printf("Input dimension of 2D Array : ");
    scanf("%d %d", &n, &k);
    int arr[n][k];
    printf("Input the elements :\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &arr[i][j]);
    int **newArr = (int **)malloc(sizeof(int) * (n - 1));
    printf("Input row number to delete : ");
    scanf("%d", &delRow);
    printf("Matrix with deleted row :\n");
    for (int i = 0; i < n - 1; i++)
    {
        if (i < delRow - 1)
            *(newArr + i) = *(arr + i);
        else
            *(newArr + i) = *(arr + i + 1);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < k; j++)
            printf("%d\t", newArr[i][j]);
        printf("\n");
    }
    return 0;
}