#include "../utils.h"

class MyLinkedList {
 public:
  MyLinkedList() {
    header = new ListNode();
    count = 0;
  }

  int get(int index) {
    if (index >= count) {
      return -1;
    } else {
      ListNode *cur = header;
      for (int i = 0; i < index; ++i) {
        cur = cur->next;
      }
      return cur->next->val;
    }
  }

  void addAtHead(int val) {
    ListNode *cur = new ListNode(val, header->next);
    header->next = cur;
    ++count;
  }

  void addAtTail(int val) {
    ListNode *cur = header;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = new ListNode(val, nullptr);
    ++count;
  }

  void addAtIndex(int index, int val) {
    if (index > count) {
      return;
    }
    ListNode *cur = header;
    for (int i = 0; i < index; ++i) {
      cur = cur->next;
    }
    ListNode *tmp = new ListNode(val, cur->next);
    cur->next = tmp;
    ++count;
  }

  void deleteAtIndex(int index) {
    if (index >= count) {
      return;
    }
    ListNode *cur = header;
    for (int i = 0; i < index; ++i) {
      cur = cur->next;
    }
    ListNode *tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    --count;
  }

 private:
  ListNode *header;
  int count;
};