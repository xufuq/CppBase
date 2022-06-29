#include "../utils.h"

TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return root;
  }
  queue<TreeNode*> que;
  que.push(root);
  TreeNode* cur;
  while (1) {
    cur = que.front();
    que.pop();
    swap(cur->left, cur->right);
    if (cur->left) que.push(cur->left);
    if (cur->right) que.push(cur->right);
    if (que.empty()) {
      break;
    }
  }
  return root;
}