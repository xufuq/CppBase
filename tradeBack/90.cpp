#include "../utils.h"

void subsetsWithDup(vector<int>& nums, vector<vector<int>>& result,
                    vector<int>& path, int start_index) {
  result.push_back(path);
  for (int i = start_index; i < nums.size(); ++i) {
    if (i > start_index && nums[i] == nums[i - 1]) {
      continue;
    }
    path.push_back(nums[i]);
    subsetsWithDup(nums, result, path, i + 1);
    path.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  sort(nums.begin(), nums.end());
  subsetsWithDup(nums, result, path, 0);
  return result;
}