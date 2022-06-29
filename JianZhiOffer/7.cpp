#include "../utils.h"

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_start,
                    int pre_end, int in_start, int in_end) {
  if (pre_start == pre_end) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(preorder[pre_start]);
  for (int i = in_start; i < in_end; ++i) {
    if (inorder[i] == root->val) {
      root->left = buildTree(preorder, inorder, pre_start + 1,
                             pre_start + 1 + i - in_start, in_start, i);
      root->right = buildTree(preorder, inorder, pre_start + 1 + i - in_start,
                              pre_end, i + 1, in_end);
      return root;
    }
  }
  return nullptr;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int pre_start = 0, pre_end = preorder.size();
  int in_start = 0, in_end = inorder.size();
  return buildTree(preorder, inorder, pre_start, pre_end, in_start, in_end);
}