#include "../utils.h"

// 层序遍历
int findBottomLeftValue(TreeNode *root) {
  int result = root->val;
  queue<TreeNode *> que;
  que.push(root);
  que.push(nullptr);
  TreeNode *cur;
  while (1) {
    cur = que.front();
    que.pop();
    if (cur) {
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else {
      if (!que.empty()) {
        result = que.front()->val;
        que.push(nullptr);
      } else {
        return result;
      }
    }
  }
  return result;
}