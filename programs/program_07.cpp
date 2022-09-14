#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  private:
    stack<int> minimum;

  public:
    stack<int> stk;
    int getMinimum() { return minimum.top(); };
    void push(int x) {
        if (stk.empty())
            minimum.push(x);
        else
            minimum.push(min(x, minimum.top()));
        stk.push(x);
    }
    void pop() {
        stk.pop();
        minimum.pop();
    }
    int top() { return stk.top(); }
};
int main() {
    MinStack s;
    s.push(72);
    s.push(31);
    s.push(10);
    s.push(44);
    s.push(14);
    cout << "Top & Minimum Element : " << s.top() << ", " << s.getMinimum()
         << endl;
    s.pop();
    cout << "Top & Minimum Element : " << s.top() << ", " << s.getMinimum()
         << endl;
    s.pop();
    s.pop();
    cout << "Top & Minimum Element : " << s.top() << ", " << s.getMinimum()
         << endl;
}