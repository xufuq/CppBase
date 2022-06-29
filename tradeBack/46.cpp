#include "../utils.h"

void permute(vector<int> &nums, vector<bool> &used, vector<vector<int>> &result,
             vector<int> &path) {
  if (path.size() == nums.size()) {
    result.push_back(path);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (used[i] == false) {
      used[i] = true;
      path.push_back(nums[i]);
      permute(nums, used, result, path);
      path.pop_back();
      used[i] = false;
    }
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> result;
  vector<int> path;
  vector<bool> used(nums.size(), false);
  permute(nums, used, result, path);
  return result;
}