#include "../utils.h"

TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
  if (left == right) {
    return nullptr;
  }
  if (left == right - 1) {
    return new TreeNode(nums[left]);
  }
  int max_index = -1;
  for (int i = left; i < right; ++i) {
    if (max_index == -1 || nums[i] > nums[max_index]) {
      max_index = i;
    }
  }
  TreeNode* root = new TreeNode(nums[max_index]);
  root->left = constructMaximumBinaryTree(nums, left, max_index);
  root->right = constructMaximumBinaryTree(nums, max_index + 1, right);
  return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  return constructMaximumBinaryTree(nums, 0, nums.size());
}