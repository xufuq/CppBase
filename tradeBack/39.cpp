#include "../utils.h"

void combinationSum(vector<int>& candidates, int target,
                    vector<vector<int>>& result, vector<int>& path,
                    int start_index) {
  if (start_index >= candidates.size()) {
    return;
  }
  if (target == 0) {
    result.push_back(path);
    return;
  } else if (target > 0) {
    path.push_back(candidates[start_index]);
    combinationSum(candidates, target - candidates[start_index], result, path,
                   start_index);
    path.pop_back();
    combinationSum(candidates, target, result, path, start_index + 1);
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> path;
  combinationSum(candidates, target, result, path, 0);
  return result;
}