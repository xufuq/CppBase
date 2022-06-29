#include "../utils.h"

void binaryTreePaths(TreeNode* root, vector<string>& result,
                     vector<int>& path) {
  path.push_back(root->val);
  if (root->left == nullptr && root->right == nullptr) {
    result.push_back(to_string(path[0]));
    for (int i = 1; i < path.size(); ++i) {
      result.back() += "->" + to_string(path[i]);
    }
  }
  if (root->left) {
    binaryTreePaths(root->left, result, path);
  }
  if (root->right) {
    binaryTreePaths(root->right, result, path);
  }
  path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> result;
  vector<int> path;
  binaryTreePaths(root, result, path);
  return result;
}