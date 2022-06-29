#include "../utils.h"

void combine(int n, int k, vector<vector<int>> &result, vector<int> &path) {
  if (n < k) return;
  if (k == 0) {
    result.push_back(path);
  } else {
    combine(n - 1, k, result, path);
    path.push_back(n);
    combine(n - 1, k - 1, result, path);
    path.pop_back();
  }
}
vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> result;
  vector<int> path;
  combine(n, k, result, path);
  return result;
}

void combine(int n, int k, vector<vector<int>> &result, vector<int> &path) {
  if (n < k) return;
  if (k == 0) {
    result.push_back(path);
  } else {
    for (int i = n; i >= k; --i) {
      path.push_back(i);
      combine(i - 1, k - 1, result, path);
      path.pop_back();
    }
  }
}