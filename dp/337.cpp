#include "../utils.h"

void rob_base(TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  int leaf = 0, leaf_leaf = 0;
  if (root->left) {
    rob_base(root->left);
    leaf += root->left->val;
    if (root->left->left) {
      leaf_leaf += root->left->left->val;
    }
    if (root->left->right) {
      leaf_leaf += root->left->right->val;
    }
  }
  int right_leaf = 0, right_left = 0, right_right = 0;
  if (root->right) {
    rob_base(root->right);
    leaf += root->right->val;
    if (root->right->left) {
      leaf_leaf += root->right->left->val;
    }
    if (root->right->right) {
      leaf_leaf += root->right->right->val;
    }
  }
  root->val = max(root->val + leaf_leaf, leaf);
}

int rob(TreeNode* root) {
  rob_base(root);
  return root->val;
}