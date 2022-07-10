#include "../utils.h"

vector<vector<int>> findContinuousSequence(int target) {
  int left = 1, right = 1;
  int sum = 0;
  vector<vector<int>> result;
  while (right < target) {
    sum += right;
    while (sum > target) {
      sum -= left;
      ++left;
    }
    if (sum == target && right > left) {
      vector<int> tmp;
      for (int i = left; i <= right; ++i) {
        tmp.push_back(i);
      }
      result.push_back(tmp);
    }
    ++right;
  }
  return result;
}