#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++)
        if (array[i] == key)
            return i;
    return -1;
}

int main(void) {
    int size, key;
    cout << "Input the size of array : ";
    cin >> size;
    int arr[size];
    cout << "Input the " << size << " elements : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Element to search for : ";
    cin >> key;
    int index = linearSearch(arr, size, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element doesn't exist in the array" << endl;
    return 0;
}