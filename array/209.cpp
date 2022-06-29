#include "../utils.h"

int minSubArrayLen(int target, vector<int>& nums) {
  int result = INT32_MAX;
  int sum = 0;
  int left = 0, right = 0;
  while (right < nums.size()) {
    sum += nums[right];
    ++right;
    while (sum >= target) {
      result = min(right - left, result);
      sum -= nums[left];
      ++left;
    }
  }
  return result == INT32_MAX ? 0 : result;
}