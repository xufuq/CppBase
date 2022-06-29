#include "../utils.h"

vector<int> findMode(TreeNode* root) {
  vector<int> result;
  int cur_count = 0, pre_val = INT32_MAX, max_count = 0;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      if (cur->val == pre_val) {
        ++cur_count;
      } else {
        if (pre_val != INT32_MAX) {
          if (cur_count == max_count) {
            result.push_back(pre_val);
          } else if (cur_count > max_count) {
            result.clear();
            result.push_back(pre_val);
            max_count = cur_count;
          }
        }
        pre_val = cur->val;
        cur_count = 1;
      }
    }
    cur = cur->right;
  }
  if (cur_count == max_count) {
    result.push_back(pre_val);
  } else if (cur_count > max_count) {
    result.clear();
    result.push_back(pre_val);
    max_count = cur_count;
  }
  return result;
}