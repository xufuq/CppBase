#include "../utils.h"

int findLengthOfLCIS(vector<int>& nums) {
  int dp = 1, result = 1;
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      ++dp;
      result = max(result, dp);
    } else {
      dp = 1;
    }
  }
  return result;
}