#include "../utils.h"

int minCameraCover_base(TreeNode* root) {
  int result = 0;
  if (root->left) {
    if (root->left->left || root->left->right) {
      result += minCameraCover(root->left);
    } else {
      root->val = 2;
      root->left->val = 1;
    }
  }
  if (root->right) {
    if (root->right->left || root->right->right) {
      result += minCameraCover(root->right);
    } else {
      root->val = 2;
      root->right->val = 1;
    }
  }
  if (root->left && root->left->val == 0) {
    root->val = 2;
    root->left->val = 1;
  }
  if (root->right && root->right->val == 0) {
    root->val = 2;
    root->right->val = 1;
  }
  if ((root->left && root->left->val == 2) ||
      (root->right && root->right->val == 2)) {
    if (root->val != 2) {
      root->val = 1;
    }
  }
  if (root->val == 2) {
    ++result;
  }
  return result;
}

int minCameraCover(TreeNode* root) {
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  int result = minCameraCover_base(root);
  if (root->val == 0) {
    ++result;
  }
  queue<TreeNode*> que;
  TreeNode* cur;
  que.push(root);
  que.push(nullptr);
  while (que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      cout << cur->val << ",";
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else {
      cout << "nullptr,";
      if (!que.empty()) {
        que.push(nullptr);
      } else {
        break;
      }
    }
  }
  return result;
}