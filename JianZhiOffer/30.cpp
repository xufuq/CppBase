#include "../utils.h"

struct StackNode {
  StackNode()
      : val(0), list_next(nullptr), num_pre(nullptr), num_next(nullptr) {}
  StackNode(int _val)
      : val(_val), list_next(nullptr), num_pre(nullptr), num_next(nullptr) {}
  int val;
  StackNode *list_next;
  StackNode *num_pre, *num_next;
};

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() { list_ahead = new StackNode(); }

  void push(int x) {
    StackNode *tmp = new StackNode(x);
    tmp->list_next = list_ahead->list_next;
    list_ahead->list_next = tmp;

    StackNode *cur = list_ahead;
    while (cur->num_next && cur->num_next->val < x) {
      cur = cur->num_next;
    }
    tmp->num_next = cur->num_next;
    tmp->num_pre = cur;
    if (cur->num_next) {
      cur->num_next->num_pre = tmp;
    }
    cur->num_next = tmp;
    std::cout << "list: ";
    for (StackNode *cur = list_ahead->list_next; cur; cur = cur->list_next) {
      std::cout << cur->val << " ";
    }
    std::cout << std::endl;
    std::cout << "num: ";
    for (StackNode *cur = list_ahead->num_next; cur; cur = cur->num_next) {
      std::cout << cur->val << " ";
    }
    std::cout << std::endl;
  }

  void pop() {
    StackNode *cur = list_ahead->list_next;
    if (!cur) {
      return;
    }
    cur->num_pre->num_next = cur->num_next;
    if (cur->num_next) {
      cur->num_next->num_pre = cur->num_pre;
    }
    list_ahead->list_next = cur->list_next;
    std::cout << "list: ";
    for (StackNode *cur = list_ahead->list_next; cur; cur = cur->list_next) {
      std::cout << cur->val << " ";
    }
    std::cout << std::endl;
    std::cout << "num: ";
    for (StackNode *cur = list_ahead->num_next; cur; cur = cur->num_next) {
      std::cout << cur->val << " ";
    }
    std::cout << std::endl;
  }

  int top() { return list_ahead->list_next->val; }

  int min() { return list_ahead->num_next->val; }

 private:
  StackNode *list_ahead;
};
