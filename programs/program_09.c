#define MAX 101
#define TABLE printf("ROW\tCOL\tVAL\n")
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} element;

int main(void) {
    element a[MAX];
    a[0].value = 0;
    printf("Enter the number of rows and columns of the matrix : ");
    scanf("%d %d", &a[0].row, &a[0].col);
    printf("Enter the elements of the matrix :\n");
    int x = 0;
    for(int i=0; i<a[0].row; i++) {
        for(int j=0; j<a[0].col; j++) {
            scanf("%d", &x);
            if(x!=0) {
                a[0].value++;
                a[a[0].value].row = i+1;
                a[a[0].value].col = j+1;
                a[a[0].value].value = x;
            }
        }
    }

    printf("\nGiven Sparse Matrix is represented as :\n");
    TABLE;
    for (int i = 1; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    return 0;
}
