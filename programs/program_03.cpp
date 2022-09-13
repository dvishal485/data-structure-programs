#include <iostream>
using namespace std;

int main(void) {
    int n, top;
    cout << "Input max array size : ";
    cin >> n;
    int a[n];
    cout << "Input number of array elements : ";
    cin >> top;
    cout << "Input array elements : ";
    for (int i = 0; i < top; i++)
        cin >> a[i];
    cout << "Array elements : ";
    for (int i = 0; i < top; i++)
        cout << a[i] << " ";
    int mid = top / 2;
    for (int i = top; i > mid; i--)
        a[i] = a[i - 1];
    cout << endl << "Input the element to be inserted : ";
    cin >> a[mid];
    top++;
    cout << "Array elements after insertion : ";
    for (int i = 0; i < top; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
