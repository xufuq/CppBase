#include "../utils.h"

int getMinimumDifference(TreeNode* root) {
  int result = INT32_MAX, pre_val = INT32_MIN;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      if (pre_val != INT32_MIN) {
        result = min(result, abs(cur->val - pre_val));
            }
      pre_val = cur->val;
      cur = cur->right;
    }
    if (result == 1) {
      return 1;
    }
  }
  return result;
}