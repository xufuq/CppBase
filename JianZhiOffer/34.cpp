#include "../utils.h"

void pathSum(TreeNode *root, int target, vector<vector<int>> &result,
             vector<int> &path) {
  target -= root->val;
  path.push_back(root->val);
  if (root->left) {
    pathSum(root->left, target, result, path);
  }
  if (root->right) {
    pathSum(root->right, target, result, path);
  }
  if (target == 0 && !root->left && !root->right) {
    result.push_back(path);
  }
  path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int target) {
  vector<vector<int>> result;
  vector<int> path;
  if (!root) {
    return result;
  }
  pathSum(root, target, result, path);
  return result;
}