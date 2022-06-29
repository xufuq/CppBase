#include "../utils.h"

ListNode *detectCycle(ListNode *head) {
  ListNode *header = new ListNode(0, head);
  ListNode *slow = header, *fast = header;
  ListNode *meet = nullptr;
  while (fast->next != nullptr) {
    fast = fast->next;
    if (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    } else {
      break;
    }

    if (slow == fast) {
      meet = slow;
      break;
    }
  }
  if (meet == nullptr) {
    return nullptr;
  }
  slow = header, fast = meet;
  while (slow->next != fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow->next;
}