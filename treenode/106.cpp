#include "../utils.h"

// 左闭右开
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_left,
                    int in_right, int post_left, int post_right) {
  if (in_left == in_right) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(postorder[post_right - 1]);
  if (in_left == in_right - 1) {
    return root;
  }
  for (int i = in_left; i < in_right; ++i) {
    if (inorder[i] == root->val) {
      root->left = buildTree(inorder, postorder, in_left, i, post_left,
                             post_left + i - in_left);
      root->right = buildTree(inorder, postorder, i + 1, in_right,
                              post_left + i - in_left, post_right - 1);
      return root;
    }
  }
  return nullptr;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
}