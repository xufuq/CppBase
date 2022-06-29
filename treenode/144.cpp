#include "../utils.h"

// 递归做法
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> result;
  preorderTraversal_base(root, result);
  return result;
}

void preorderTraversal_base(TreeNode *root, vector<int> &result) {
  if (root != nullptr) {
    result.push_back(root->val);
    preorderTraversal_base(root->left, result);
    preorderTraversal_base(root->right, result);
  }
}

// 迭代做法
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> result;
  if (root == nullptr) return result;
  stack<TreeNode *> st;
  st.push(root);
  TreeNode *cur;
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    result.push_back(cur->val);
    if (cur->right) st.push(cur->right);
    if (cur->left) st.push(cur->left);
  }
  return result;
}