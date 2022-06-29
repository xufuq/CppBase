#include "../utils.h"

void findSubsequences(vector<int>& nums, vector<vector<int>>& result,
                      vector<int>& path, int start_index) {
  if (path.size() > 1) {
    result.push_back(path);
  }
  unordered_set<int> used;
  for (int i = start_index; i < nums.size(); ++i) {
    if (used.find(nums[i]) != used.end()) {
      continue;
    }
    if (path.empty() || nums[i] >= path.back()) {
      used.insert(nums[i]);
      path.push_back(nums[i]);
      findSubsequences(nums, result, path, i + 1);
      path.pop_back();
    }
  }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  findSubsequences(nums, result, path, 0);
  return result;
}