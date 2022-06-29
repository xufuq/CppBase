#include "../utils.h"

vector<int> rightSideView(TreeNode* root) {
  vector<int> result;
  if (root == nullptr) {
    return result;
  }
  queue<TreeNode*> que;
  que.push(root);
  que.push(nullptr);
  TreeNode* cur;
  while (1) {
    cur = que.front();
    que.pop();
    if (cur) {
      if (que.front() == nullptr) {
        result.push_back(cur->val);
      }
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else {
      if (que.empty()) {
        break;
      } else {
        que.push(nullptr);
      }
    }
  }
  return result;
}