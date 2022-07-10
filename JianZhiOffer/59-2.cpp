#include "../utils.h"
// 和59-2一样的思路，没有那么难
class MaxQueue {
 public:
  MaxQueue() {}

  int max_value() {
    if (sort_que.empty()) {
      return -1;
    }
    return sort_que.front();
  }

  void push_back(int value) {
    que.push(value);
    while (!sort_que.empty() && sort_que.back() < value) {
      sort_que.pop_back();
    }
    sort_que.push_back(value);
  }

  int pop_front() {
    if (que.empty()) {
      return -1;
    }
    if (que.front() == sort_que.front()) {
      sort_que.pop_front();
    }
    int num = que.front();
    que.pop();
    return num;
  }

  queue<int> que;
  deque<int> sort_que;
};