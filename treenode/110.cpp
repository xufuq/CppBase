#include "../utils.h"

bool isBalanced(TreeNode* root, int& depth) {
  if (root == nullptr) {
    depth = 0;
    return true;
  }
  int depth_left = 0, depth_right = 0;
  if (isBalanced(root->left, depth_left) &&
      isBalanced(root->right, depth_right) &&
      abs(depth_left - depth_right) < 2) {
    depth = 1 + max(depth_left, depth_right);
    return true;
  }
  return false;
}

bool isBalanced(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  int depth = 0;
  return isBalanced(root, depth);
}