#include "../utils.h"

// 递归
bool isSymmetric(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left && right && left->val == right->val) {
    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
  return false;
}

bool isSymmetric(TreeNode* root) {
  return isSymmetric(root->left, root->right);
}

// 迭代

bool isSymmetric(TreeNode* root) {
  queue<TreeNode*> que;
  que.push(root->left);
  que.push(root->right);
  TreeNode *L, *R;
  while (!que.empty()) {
    L = que.front();
    que.pop();
    R = que.front();
    que.pop();
    if (L == nullptr && R == nullptr) {
      continue;
    } else if (L && R && L->val == R->val) {
      que.push(L->left);
      que.push(R->right);
      que.push(L->right);
      que.push(R->left);
    } else {
      return false;
    }
  }
  return true;
}