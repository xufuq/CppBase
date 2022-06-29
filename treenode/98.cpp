#include "../utils.h"

bool isValidBST(TreeNode *root) {
  vector<int> result;
  stack<TreeNode *> st;
  TreeNode *cur = root;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      result.push_back(cur->val);
      cur = cur->right;
    }
  }
  for (int i = 1; i < result.size(); ++i) {
    if (result[i - 1] >= result[i]) {
      return false;
    }
  }
  return true;
}

bool isValidBST(TreeNode *root) {
  int last_val = INT32_MIN;
  bool first_val = true;
  stack<TreeNode *> st;
  TreeNode *cur = root;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      if (first_val) {
        last_val = cur->val;
        first_val = false;
      } else if (last_val >= cur->val) {
        return false;
      }
      last_val = cur->val;
      cur = cur->right;
    }
  }
  return true;
}