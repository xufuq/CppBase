#include "../utils.h"

void subsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& path,
             int start_index) {
  result.push_back(path);
  for (int i = start_index; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    subsets(nums, result, path, i + 1);
    path.pop_back();
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  subsets(nums, result, path, 0);
  return result;
}