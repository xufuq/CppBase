#include "../utils.h"

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in.push(x); }

  int pop() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
    int x = out.top();
    out.pop();
    return x;
  }

  int peek() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }

  bool empty() { return (out.empty() && in.empty()); }

 private:
  stack<int> out, in;
};
