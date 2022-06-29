#include "../utils.h"

static bool cmp(vector<int> &lhs, vector<int> &rhs) {
  if (lhs[0] < rhs[0]) {
    return true;
  } else if (lhs[0] == rhs[0] && lhs[1] < rhs[1]) {
    return true;
  }
  return false;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(), cmp);
  int n = intervals.size(), end = INT32_MIN, result = 0;
  for (auto &vals : intervals) {
    if (vals[0] < end) {
      ++result;
      end = min(end, vals[1]);
    } else {
      end = vals[1];
    }
  }
  return result;
}