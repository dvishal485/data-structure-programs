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
    int non_zero_terms;
    SparseMatrix(void)
    {
        non_zero_terms = 0;
        rows = 0;
        columns = 0;
    }
    SparseMatrix(const SparseMatrix *s)
    {
        rows = s->rows;
        columns = s->columns;
        elements = s->elements;
        non_zero_terms = s->non_zero_terms;
    }
    SparseMatrix(const int *arr, int r, int c)
    {
        rows = r;
        columns = c;
        elements = new Element[r * c];
        int non_zero = 0;
        for (int i = 0; i < r; i++)
        {
            int k = i * c;
            for (int j = 0; j < c; j++)
            {
                if (arr[k] != 0)
                {
                    Element *element = &elements[non_zero++];
                    element->row = i;
                    element->column = j;
                    element->value = arr[k];
                }
                k++;
            }
        }
        elements = (Element *)realloc(elements, sizeof(Element) * non_zero);
        non_zero_terms = non_zero;
    }

    SparseMatrix add(SparseMatrix s)
    {
        if (s.rows != rows || s.columns != columns)
        {
            cout << "ERROR : Addition is only possible for same dimension matrix" << endl;
            return SparseMatrix();
        }
        Element *result = new Element[rows * columns];
        int t1 = 0, t2 = 0, result_terms = 0;
        while (t1 < non_zero_terms && t2 < s.non_zero_terms)
        {
            if (elements[t1].row < s.elements[t2].row)
            {
                result[result_terms].row = elements[t1].row;
                result[result_terms].column = elements[t1].column;
                result[result_terms++].value = elements[t1++].value;
            }
            else if (elements[t1].row > s.elements[t2].row)
            {
                result[result_terms].row = s.elements[t2].row;
                result[result_terms].column = s.elements[t2].column;
                result[result_terms++].value = s.elements[t2++].value;
            }
            else
            {
                if (elements[t1].column < s.elements[t2].column)
                {
                    result[result_terms].row = elements[t1].row;
                    result[result_terms].column = elements[t1].column;
                    result[result_terms++].value = elements[t1++].value;
                }
                else if (elements[t1].row > s.elements[t2].row)
                {
                    result[result_terms].row = s.elements[t2].row;
                    result[result_terms].column = s.elements[t2].column;
                    result[result_terms++].value = s.elements[t2++].value;
                }
                else
                {
                    int sum = elements[t1].value + s.elements[t2].value;
                    if (sum != 0)
                    {
                        result[result_terms].row = elements[t1].row;
                        result[result_terms].column = elements[t1].column;
                        result[result_terms++].value = sum;
                    }
                    t1++;
                    t2++;
                }
            }
        }

        while (t1 < non_zero_terms)
        {
            result[result_terms].row = elements[t1].row;
            result[result_terms].column = elements[t1].column;
            result[result_terms++].value = elements[t1++].value;
        }
        while (t2 < s.non_zero_terms)
        {
            result[result_terms].row = s.elements[t2].row;
            result[result_terms].column = s.elements[t2].column;
            result[result_terms++].value = s.elements[t2++].value;
        }
        result = (Element *)realloc(result, sizeof(Element) * result_terms);

        SparseMatrix m = SparseMatrix();
        m.rows = rows;
        m.columns = columns;
        m.elements = result;
        m.non_zero_terms = result_terms;
        return m;
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

        for (int i = 0; i < non_zero_terms; i++)
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

    SparseMatrix transpose()
    {
        SparseMatrix result = SparseMatrix();
        result.elements = new Element[non_zero_terms];
        for (int i = 0; i < non_zero_terms; i++)
        {
            result.elements[i].column = elements[i].row;
            result.elements[i].row = elements[i].column;
            result.elements[i].value = elements[i].value;
        }
        result.columns = rows;
        result.rows = columns;
        result.non_zero_terms = non_zero_terms;
        return result;
    }
};

int main()
{
    int arr[5][4] = {{7, 0, 3, 0},
                     {0, 4, 0, 9},
                     {-5, 7, 0, 0},
                     {0, 2, 0, 0},
                     {12, 0, 2, 0}};
    int arr2[5][4] = {{0, 0, 3, 0},
                      {4, 0, 0, 9},
                      {-5, 1, 2, 0},
                      {0, 2, 0, 0},
                      {-6, 0, -2, 0}};

    SparseMatrix m = SparseMatrix((int *)arr, 5, 4);
    printf("Generated Sparse Matrix 1 \n");
    m.printSparseMatrix();

    SparseMatrix n = SparseMatrix((int *)arr2, 5, 4);
    printf("Generated Sparse Matrix 2 :\n");
    n.printSparseMatrix();

    printf("Addition of Sparse Matrix 1 and 2 :\n");
    SparseMatrix x = n.add(m);
    x.printSparseMatrix();

    SparseMatrix y = x.transpose();
    printf("Transposed Sparse Matrix :\n");
    y.printSparseMatrix();
    return 0;
}