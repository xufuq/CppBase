#include "../utils.h"

int countNodes(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

// 优化方法
int countNodes(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  TreeNode* cur = root->left;
  int left_count = 0, right_count = 0;
  while (cur != nullptr) {
    ++left_count;
    cur = cur->left;
  }
  cur = root->right;
  while (cur != nullptr) {
    ++right_count;
    cur = cur->right;
  }
  if (left_count == right_count) {
    return (1 << left_count) - 1;
  } else {
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
}