#include "../utils.h"

vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> result;
  vector<int> res;
  if (root == nullptr) {
    return result;
  }
  queue<TreeNode*> que;
  que.push(root);
  que.push(nullptr);
  TreeNode* cur;
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      res.push_back(cur->val);
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else {
      result.push_back(res);
      res.clear();
      if (!que.empty()) {
        que.push(nullptr);
      }
    }
  }
  reverse(result.begin(), result.end());
  return result;
}