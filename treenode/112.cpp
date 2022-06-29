#include "../utils.h"

bool hasPathSum(TreeNode* root, int targetSum) {
  if (root) {
    if (root->left == nullptr && root->right == nullptr &&
        targetSum == root->val) {
      return true;
    }
    if (hasPathSum(root->left, targetSum - root->val)) {
      return true;
    }
    if (hasPathSum(root->right, targetSum - root->val)) {
      return true;
    }
  }
  return false;
}
