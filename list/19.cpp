#include "../utils.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* header = new ListNode(0, head);
  ListNode *slow = header, *fast = header;
  while (n--) {
    fast = fast->next;
  }
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return header->next;
}