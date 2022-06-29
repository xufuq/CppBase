#include "../utils.h"

vector<int> reversePrint(ListNode* head) {
  int count = 0;
  ListNode *tmp = nullptr, *pre = nullptr, *cur = head;
  while (cur) {
    ++count;
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  vector<int> result(count);
  count = 0;
  cur = pre;
  while (cur) {
    result[count++] = cur->val;
    cur = cur->next;
  }
  return result;
}