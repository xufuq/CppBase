#include "../utils.h"

TreeNode* insertIntoBST(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }
  TreeNode* cur = root;
  while (cur) {
    if (val < cur->val) {
      if (cur->left == nullptr) {
        cur->left = new TreeNode(val);
        return root;
      } else {
        cur = cur->left;
      }
    } else {
      if (cur->right == nullptr) {
        cur->right = new TreeNode(val);
        return root;
      } else {
        cur = cur->right;
      }
    }
  }
  return root;
}