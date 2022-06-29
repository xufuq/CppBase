#include "../utils.h"

void combinationSum2(vector<int>& candidates, int target,
                     vector<vector<int>>& result, vector<int>& path,
                     int start_index) {
  if (target == 0) {
    result.push_back(path);
    return;
  } else if (target < 0) {
    return;
  }
  if (start_index >= candidates.size()) {
    return;
  }
  for (int i = start_index; i < candidates.size(); ++i) {
    if (i > start_index && candidates[i] == candidates[i - 1]) {
      continue;
    }
    path.push_back(candidates[i]);
    combinationSum2(candidates, target - path.back(), result, path, i + 1);
    path.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> result;
  vector<int> path;
  combinationSum2(candidates, target, result, path, 0);
  return result;
}