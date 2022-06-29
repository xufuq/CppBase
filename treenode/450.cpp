#include "../utils.h"

TreeNode* deleteNode(TreeNode* root, int key) {
  if (root == nullptr) {
    return root;
  } else if (root->val == key) {
    if (root->left == nullptr) {
      return root->right;
    } else if (root->right == nullptr) {
      return root->left;
    } else {
      TreeNode *cur = root->left, *pre = nullptr;
      while (cur->right != nullptr) {
        pre = cur;
        cur = cur->right;
      }
      if (pre) {
        pre->right = nullptr;
        cur->left = root->left;
      }
      if (cur != root->left) {
            }
      cur->right = root->right;
      return cur;
    }
  } else if (key < root->val) {
    root->left = deleteNode(root->left, key);
  } else {
    root->right = deleteNode(root->right, key);
  }
  return root;
}