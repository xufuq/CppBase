#include "../utils.h"

void permuteUnique(vector<int> &nums, vector<int> &used,
                   vector<vector<int>> &result, vector<int> &path) {
  if (path.size() == nums.size()) {
    result.push_back(path);
    return;
  }
  int pre_index = -1;
  for (int i = 0; i < nums.size(); ++i) {
    if (used[i] == false) {
      if (pre_index != -1 && nums[i] == nums[pre_index]) {
        continue;
      }
      pre_index = i;
      used[i] = true;
      path.push_back(nums[i]);
      permuteUnique(nums, used, result, path);
      path.pop_back();
      used[i] = false;
    }
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> result;
  vector<int> path;
  vector<int> used(nums.size(), false);
  permuteUnique(nums, used, result, path);
  return result;
}