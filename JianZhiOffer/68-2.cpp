#include "../utils.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) {
    return nullptr;
  }
  if (root == p || root == q) {
    return root;
  }
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  if (left && right) {
    return root;
  } else if (left) {
    return left;
  } else {
    return right;
  }
}