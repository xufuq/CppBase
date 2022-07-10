#include "../utils.h"

int getDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }
  int left = getDepth(root->left);
  int right = getDepth(root->right);
  if (left < 0 || right < 0 || abs(left - right) > 1) {
    return -1;
  }
  return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) { return getDepth(root) != -1; }