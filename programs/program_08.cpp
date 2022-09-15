#include <iostream>
#include <stack>
using namespace std;

class DasMinStack {
    int min;
    stack<int> s;

  public:
    void push(int);
    void pop();
    int top();
    int getMin() { return min; }
};

void DasMinStack::push(int element) {
    if (s.empty()) {
        s.push(0);
        min = element;
    } else {
        s.push(element - min);
        if (element < min)
            min = element;
    }
}

int DasMinStack::top() {
    int x = s.top() + min;
    if (x > 0)
        return x;
    else
        return min;
}

void DasMinStack::pop() {
    int x = s.top();
    s.pop();
    if (x < 0)
        min = min - x;
}

int main() {
    DasMinStack s;
    s.push(31);
    s.push(72);
    cout << s.getMin() << endl;
    s.push(10);
    s.push(45);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}