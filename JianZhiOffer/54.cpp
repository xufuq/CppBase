#include "../utils.h"

// 右中左， 后续遍历
int kthLargest(TreeNode* root, int k) {
  TreeNode* cur = root;
  stack<TreeNode*> st;
  while (cur != nullptr || !st.empty()) {
    if (!cur) {
      st.push(cur);
      cur = cur->right;
    } else {
      cur = st.top();
      st.pop();
      if (k == 1) {
        return cur->val;
      }
      --k;
      cur = cur->left;
    }
  }
  return 0;
}