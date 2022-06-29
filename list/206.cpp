#include "../utils.h"

ListNode* reverseList(ListNode* head) {
  ListNode *pre = nullptr, *tmp = nullptr;
  while (head != nullptr) {
    tmp = head->next;
    head->next = pre;
    pre = head;
    head = tmp;
  }
  return pre;
}