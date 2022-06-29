#include "../utils.h"

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    if (in.empty()) {
      out.push(x);
    } else {
      in.push(x);
    }
  }

  int pop() {
    if (in.empty()) {
      while (out.size() != 1) {
        in.push(out.front());
        out.pop();
      }
      int x = out.front();
      out.pop();
      return x;
    } else {
      while (in.size() != 1) {
        out.push(in.front());
        in.pop();
      }
      int x = in.front();
      in.pop();
      return x;
    }
  }

  int top() {
    if (in.empty()) {
      while (out.size() != 1) {
        in.push(out.front());
        out.pop();
      }
      int x = out.front();
      out.pop();
      in.push(x);
      return x;
    } else {
      while (in.size() != 1) {
        out.push(in.front());
        in.pop();
      }
      int x = in.front();
      in.pop();
      out.push(x);
      return x;
    }
  }

  bool empty() { return in.empty() && out.empty(); }

 private:
  queue<int> out, in;
};