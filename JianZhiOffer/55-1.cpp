#include "../utils.h"

int maxDepth(TreeNode* root) {
  if (!root) return 0;
  int result = 1;
  queue<TreeNode*> que;
  TreeNode* cur = root;
  que.push(root);
  que.push(nullptr);
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else if (!que.empty()) {
      que.push(nullptr);
      ++result;
    } else {
      return result;
    }
  }
  return result;
}