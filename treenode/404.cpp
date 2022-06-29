#include "../utils.h"

bool sumOfLeftLeaves(TreeNode* root, int& sum) {
  if (root->left == nullptr && root->right == nullptr) {
    return true;
  }
  int sum_left = 0, sum_right = 0;
  if (root->left && sumOfLeftLeaves(root->left, sum_left)) {
    sum_left = root->left->val;
  }
  if (root->right && sumOfLeftLeaves(root->right, sum_right)) {
    sum_right = 0;
  }
  sum = sum_left + sum_right;
  return false;
}

int sumOfLeftLeaves(TreeNode* root) {
  int sum = 0;
  sumOfLeftLeaves(root, sum);
  return sum;
}