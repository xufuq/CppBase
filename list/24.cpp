#include "../utils.h"

ListNode* swapPairs(ListNode* head) {
  ListNode *header = new ListNode(0, head), *cur = header;
  while (cur->next != nullptr && cur->next->next != nullptr) {
    ListNode* left = cur->next;
    ListNode* right = left->next;
    left->next = right->next;
    right->next = left;
    cur->next = right;
    cur = left;
  }
  return header->next;
}