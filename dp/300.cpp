#include "../utils.h"

int lengthOfLIS(vector<int>& nums) {
  int result = 1, n = nums.size();
  vector<int> dp(n, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    result = max(result, dp[i]);
  }
  return result;
}