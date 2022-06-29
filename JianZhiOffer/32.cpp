#include "../utils.h"

vector<int> levelOrder(TreeNode* root) {
  vector<int> result;
  if (!root) {
    return result;
  }
  queue<TreeNode*> que;
  que.push(root);
  que.push(nullptr);
  TreeNode* cur;
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (!cur) {
      if (que.empty()) {
        return result;
      } else {
        que.push(nullptr);
      }
    } else {
      result.push_back(cur->val);
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    }
  }
  return result;
}