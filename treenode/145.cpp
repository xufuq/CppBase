#include "../utils.h"

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> result;
  postorderTraversal_base(root, result);
  return result;
}

void postorderTraversal_base(TreeNode* root, vector<int>& result) {
  if (root == nullptr) {
    return;
  }
  postorderTraversal_base(root->left, result);
  postorderTraversal_base(root->right, result);
  result.push_back(root->val);
}

// 迭代做法
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> result;
  if (root == nullptr) {
    return result;
  }
  stack<TreeNode*> st;
  st.push(root);
  TreeNode* cur;
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    result.push_back(cur->val);
    if (cur->left) st.push(cur->left);
    if (cur->right) st.push(cur->right);
  }
  reverse(result.begin(), result.end());
  return result;
}
