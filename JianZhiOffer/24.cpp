#include "../utils.h"

ListNode *reverseList(ListNode *head) {
  ListNode *pre = nullptr;
  ListNode *cur = head;
  ListNode *tmp = nullptr;
  while (cur) {
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}