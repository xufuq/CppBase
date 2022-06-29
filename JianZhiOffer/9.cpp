#include "../utils.h"

class CQueue {
 public:
  CQueue() {}

  void appendTail(int value) { st2.push(value); }

  int deleteHead() {
    if (st1.empty()) {
      while (!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
      }
    }
    if (st1.empty()) {
      return -1;
    }
    int result = st1.top();
    st1.pop();
    return result;
  }

 private:
  stack<int> st1, st2;
};