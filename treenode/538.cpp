#include "../utils.h"

// 右中左
TreeNode* convertBST(TreeNode* root) {
  int sum = 0;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->right;
    } else {
      cur = st.top();
      st.pop();
      sum += cur->val;
      cur->val = sum;
      cur = cur->left;
    }
  }
  return root;
}