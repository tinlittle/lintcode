#include <vector>
#include <stack>

class MinStack {
private:
  std::stack<int> valueStack;
  std::stack<int> minStack;
public:
    MinStack() {}

    void push(int number) {
      valueStack.push(number);
      if (minStack.empty() || number <= minStack.top())
        minStack.push(number);
    }

    int pop() {
      int top = valueStack.top();
      if (top == minStack.top())
        minStack.pop();
      valueStack.pop();
      return top;
    }

    int min() {
      return minStack.top();
    }
};