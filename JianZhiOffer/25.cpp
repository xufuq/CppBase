#include "../utils.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* ahead = new ListNode();
  ListNode* cur = ahead;
  while (l1 && l2) {
    if (l1->val > l2->val) {
      cur->next = l2;
      l2 = l2->next;
    } else {
      cur->next = l1;
      l1 = l1->next;
    }
    cur = cur->next;
  }
  while (l1) {
    cur->next = l1;
    l1 = l1->next;
    cur = cur->next;
  }
  while (l2) {
    cur->next = l2;
    l2 = l2->next;
    cur = cur->next;
  }
  return ahead->next;
}