#include "../utils.h"

TreeNode* searchBST(TreeNode* root, int val) {
  while (root) {
    if (root->val > val) {
      root = root->left;
    } else if (root->val < val) {
      root = root->right;
    } else {
      break;
    }
  }
  return root;
}