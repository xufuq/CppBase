#include "../utils.h"

bool isSame(TreeNode* A, TreeNode* B) {
  if (B == nullptr) {
    return true;
  } else if (A && A->val == B->val) {
    return isSame(A->left, B->left) && isSame(A->right, B->right);
  }
  return false;
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
  if (B == nullptr) {
    return false;
  }
  queue<TreeNode*> que;
  que.push(A);
  que.push(nullptr);
  TreeNode* cur;
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      if (cur->val == B->val && isSame(cur, B)) {
        return true;
      }
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else if (!que.empty()) {
      que.push(nullptr);
    }
  }
  return false;
}