#include "../utils.h"

static bool cmp(vector<int> &lhs, vector<int> &rhs) {
  if (lhs[0] < rhs[0]) {
    return true;
  } else if (lhs[0] == rhs[0] && lhs[1] < rhs[1]) {
    return true;
  }
  return false;
}

int findMinArrowShots(vector<vector<int>> &points) {
  sort(points.begin(), points.end(), cmp);
  int n = points.size();
  vector<int> vec(2);
  vec[0] = INT32_MIN, vec[1] = INT32_MAX;
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (vec[0] <= points[i][1] && vec[1] >= points[i][0]) {
      vec[0] = max(vec[0], points[i][0]);
      vec[1] = min(vec[1], points[i][1]);
    } else {
      ++result;
      vec[0] = points[i][0];
      vec[1] = points[i][1];
    }
  }
  return result + 1;
}