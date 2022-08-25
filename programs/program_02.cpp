#include <iostream>
using namespace std;

int binarySearch(int array[], int key, int right_index)
{
    int left_index = 0;
    while (left_index <= right_index)
    {
        int mid_index = (left_index + right_index) / 2;
        int middle_element = array[mid_index];
        if (middle_element == key)
            return mid_index;
        else if (middle_element > key)
            right_index = mid_index - 1;
        else
            left_index = mid_index + 1;
    }
    return -1;
}

int main(void)
{
    int size, key;
    cout << "Input the size of sorted array (ascending) : ";
    cin >> size;
    int arr[size];
    cout << "Input the " << size << " elements : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Element to search for : ";
    cin >> key;
    int index = binarySearch(arr, key, size);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element doesn't exist in the array" << endl;
    return 0;
}