#include "../utils.h"

TreeNode* trimBST(TreeNode* root, int low, int high) {
  if (root == nullptr) {
    return root;
  } else if (root->val < low) {
    return trimBST(root->right, low, high);
  } else if (root->val > high) {
    return trimBST(root->left, low, high);
  } else {
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
}