#include <iostream>
using namespace std;

class Element
{
public:
    int row;
    int column;
    int value;
};

class SparseMatrix
{
public:
    Element *elements;
    int rows;
    int columns;
    int terms;
    SparseMatrix(const int *arr, int r, int c)
    {
        rows = r;
        columns = c;
        elements = new Element[r * c];
        int non_zero = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (arr[i + j * c] != 0)
                {
                    Element *element = &elements[non_zero++];
                    element->row = i;
                    element->column = j;
                    element->value = arr[i * c + j];
                }
            }
        }
        elements = (Element *)realloc(elements, sizeof(Element) * non_zero);
        terms = non_zero;
    }

    void printSparseMatrix()
    {
        int array[rows][columns];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                array[i][j] = 0;
            }
        }

        for (int i = 0; i < terms; i++)
        {
            Element elem = elements[i];
            array[elem.row][elem.column] = elem.value;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf("%d\t", array[i][j]);
            }
            printf("\n");
        }
    }
};

int main()
{
    int arr[5][4] = {{7, 0, 3, 0},
                     {0, 4, 0, 9},
                     {-5, 7, 0, 0},
                     {0, 2, 0, 0},
                     {12, 0, -2, 0}};

    SparseMatrix m = SparseMatrix((int *)arr, 5, 4);
    printf("Generated Sparse Matrix :\n");
    m.printSparseMatrix();
    return 0;
}