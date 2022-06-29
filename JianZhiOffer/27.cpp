#include "../utils.h"

TreeNode* mirrorTree(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  queue<TreeNode*> que;
  que.push(root);
  que.push(nullptr);
  TreeNode* cur;
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      TreeNode* tmp = cur->left;
      cur->left = cur->right;
      cur->right = tmp;
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else if (!que.empty()) {
      que.push(nullptr);
    }
  }
  return root;
}