#include <iostream>
using namespace std;
int main(void)
{
    int n, k, delRow;
    cout << "Input dimension of 2D Array : ";
    cin >> n >> k;
    int arr[n][k];
    cout << "Input the elements : " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> arr[i][j];

    int **newArr = (int **)malloc(sizeof(int **) * (n - 1) * k);
    cout
        << "Input row number to delete : ";
    cin >> delRow;
    cout << endl
         << "Matrix with deleted row : " << endl;
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
            cout << newArr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
