#include "../utils.h"

ListNode* deleteNode(ListNode* head, int val) {
  if (head == nullptr) {
    return nullptr;
  }
  if (head->val == val) {
    return head->next;
  }
  ListNode *pre = head, *cur = head->next;
  while (cur) {
    if (cur->val == val) {
      pre->next = cur->next;
      return head;
    }
    pre = cur;
    cur = cur->next;
  }
  return head;
}