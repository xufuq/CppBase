#include "../utils.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int aCount = 0, bCount = 0;
  ListNode *cur = headA;
  while (cur != nullptr) {
    cur = cur->next;
    ++aCount;
  }
  cur = headB;
  while (cur != nullptr) {
    cur = cur->next;
    ++bCount;
  }
  ListNode *aCur = headA, *bCur = headB;
  int ab = aCount - bCount;
  if (ab > 0) {
    while (ab--) {
      aCur = aCur->next;
    }
  } else {
    ab = -ab;
    while (ab--) {
      bCur = bCur->next;
    }
  }

  while (aCur != nullptr) {
    if (aCur == bCur) {
      return aCur;
    }
    aCur = aCur->next;
    bCur = bCur->next;
  }
  return aCur;
}