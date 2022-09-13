/*
This program is written by Vivek Yadav
*/

#include <iostream>
using namespace std;

class Stack {
    int capacity;
    int top;
    int *arr;

    void copy_and_relocate(int old_cap, int new_cap) {
        int *temp = arr;
        arr = new int[new_cap];

        for (int i = 0; i < old_cap; i++)
            arr[i] = temp[i];

        if (temp != nullptr)
            delete[] temp;
    }

  public:
    Stack() : capacity(5), top(-1), arr(nullptr) {
        copy_and_relocate(0, capacity);
    }
    Stack(int cap) : capacity(cap), top(-1), arr(nullptr) {
        copy_and_relocate(0, capacity);
    }

    void push(int x) {
        cout << x << " pushed!" << endl;
        if (top == capacity - 1) {
            copy_and_relocate(capacity, capacity * 2);
            capacity *= 2;
        }

        arr[++top] = x;
    }

    int pop() {
        if (top == -1)
            return INT32_MIN;
        cout << arr[top] << " popped!" << endl;
        return arr[top--];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(10);
    s.push(5);
    s.push(10);
    s.push(3);
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.push(5);
    s.display();

    return 0;
}