#include <iostream>
using namespace std;

class DualStack {
    int top1;
    int top2;
    int capacity;

  public:
    int *array;
    DualStack(int c) {
        capacity = c;
        array = new int[c];
        top1 = -1;
        top2 = c;
    }
    void push(int, int);
    void pop(int);
    int top(int);
    bool isEmpty(int stack_id);
    bool isFull();
    void displayStackTop() {
        cout << "Stack 1 : " << top(1) << endl;
        cout << "Stack 2 : " << top(2) << endl;
        cout << endl;
    }
};

void DualStack::push(int x, int stack_id) {
    if (top1 + 1 == top2) {
        cout << "Error : Stack Overflow" << endl;
        return;
    }
    if (stack_id == 1)
        array[++top1] = x;
    else if (stack_id == 2)
        array[--top2] = x;
    else
        cout << "Invalid Stack ID" << endl;
}

void DualStack::pop(int stack_id) {
    if (stack_id == 1) {
        if (top1 != -1)
            top1--;
        else
            cout << "Stack 1 is already empty";
    } else if (stack_id == 2) {
        if (top2 != capacity)
            top2++;
        else
            cout << "Stack 2 is already empty";
    } else
        cout << "Invalid Stack ID" << endl;
}

int DualStack::top(int stack_id) {
    if (stack_id == 1)
        return array[top1];
    else if (stack_id == 2)
        return array[top2];
    else
        cout << "Invalid Stack ID" << endl;
    return INT32_MIN;
}

bool DualStack::isEmpty(int stack_id) {
    if (stack_id == 1)
        return top1 == -1;
    if (stack_id == 2)
        return top2 == capacity;
    else
        cout << "Invalid Stack ID" << endl;
    return 0;
}

bool DualStack::isFull() { return top1 == top2 - 1; }

int main(void) {
    DualStack s(10);

    cout << "Stack 1 is empty : " << s.isEmpty(1) << endl
         << "Stack 2 is empty : " << s.isEmpty(2) << endl
         << "Stack is full : " << s.isFull() << endl
         << endl;

    s.push(11, 1);
    s.push(12, 2);
    s.push(13, 1);
    s.push(14, 1);
    s.push(15, 2);
    s.push(16, 1);
    s.displayStackTop();

    s.pop(1);
    s.displayStackTop();

    s.push(17, 1);
    s.push(18, 2);
    s.push(19, 2);
    s.displayStackTop();

    s.push(20, 1);
    s.push(21, 2);
    s.displayStackTop();

    s.push(22, 1); // should give stack overflow
    s.pop(2);      // make space from stack 2
    s.push(22, 1); // use that empty space for stack 1
    s.displayStackTop();
    cout << "Stack 1 is empty : " << s.isEmpty(1) << endl
         << "Stack 2 is empty : " << s.isEmpty(2) << endl
         << "Stack is full : " << s.isFull() << endl;

    return 0;
}