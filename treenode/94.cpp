#include "../utils.h"

// 递归
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> result;
  inorderTraversal_base(root, result);
  return result;
}

void inorderTraversal_base(TreeNode *root, vector<int> &result) {
  if (root == nullptr) {
    return;
  }
  inorderTraversal_base(root->left, result);
  result.push_back(root->val);
  inorderTraversal_base(root->right, result);
}

// 迭代
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> result;
  if (root == nullptr) {
    return result;
  }
  stack<TreeNode *> st;
  st.push(root);
  TreeNode *cur;
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    if (cur != nullptr) {
      st.push(cur->right);
      st.push(cur);
      st.push(cur->left);
    } else if (!st.empty()) {
      cur = st.top();
      st.pop();
      if (cur != nullptr) {
        result.push_back(cur->val);
      }
    }
  }
  return result;
}

// 官方解法
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> result;
  stack<TreeNode *> st;
  TreeNode *cur = root;
  while (cur != NULL || !st.empty()) {
    if (cur != NULL) {  // 指针来访问节点，访问到最底层
      st.push(cur);     // 将访问的节点放进栈
      cur = cur->left;  // 左
    } else {
      // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
      cur = st.top();
      st.pop();
      result.push_back(cur->val);  // 中
      cur = cur->right;            // 右
    }
  }
  return result;
}