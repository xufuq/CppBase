#include "../utils.h"

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
  if (start == end - 1) {
    return new TreeNode(nums[start]);
  } else if (start < end) {
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
  } else {
    return nullptr;
  }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return sortedArrayToBST(nums, 0, nums.size());
}