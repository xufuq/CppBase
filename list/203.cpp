#include "../utils.h"

ListNode* removeElements(ListNode* head, int val) {
  ListNode* header = new ListNode(0, head);
  ListNode* cur = header;
  while (cur->next != nullptr) {
    if (cur->next->val == val) {
      ListNode* del = cur->next;
      cur->next = del->next;
      delete del;
    } else {
      cur = cur->next;
    }
  }
  return header->next;
}