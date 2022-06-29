#include "../utils.h"

bool isSymmetric(TreeNode* lhs, TreeNode* rhs) {
  if (lhs == nullptr && rhs == nullptr) {
    return true;
  }
  if (lhs == nullptr || rhs == nullptr) {
    return false;
  }
  if (lhs->val != rhs->val) {
    return false;
  }
  return isSymmetric(lhs->left, rhs->right) &&
         isSymmetric(lhs->right, rhs->left);
}

bool isSymmetric(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return isSymmetric(root->left, root->right);
}