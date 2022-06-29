#include "../utils.h"

void combinationSum3(int k, int n, int start_index, vector<vector<int>> &result,
                     vector<int> &path) {
  if (10 - start_index < k) {
    return;
  }
  if (k == 0 && n == 0) {
    result.push_back(path);
  } else if (k > 0 && n >= start_index) {
    for (int i = start_index; i < 10; ++i) {
      path.push_back(i);
      combinationSum3(k - 1, n - i, i + 1, result, path);
      path.pop_back();
    }
  }
}
vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> result;
  vector<int> path;
  combinationSum3(k, n, 1, result, path);
  return result;
}