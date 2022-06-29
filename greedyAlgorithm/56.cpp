#include "../utils.h"

static bool cmp(vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; }

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(), cmp);
  vector<vector<int>> result;
  int start = intervals[0][0], end = intervals[0][1];
  for (auto &vals : intervals) {
    if (vals[0] <= end) {
      end = max(end, vals[1]);
    } else {
      result.push_back({start, end});
      start = vals[0], end = vals[1];
    }
  }
  result.push_back({start, end});
  return result;
}