#include "../utils.h"

int rob(vector<int>& nums) {
  int result = 0, n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  result = dp[n];
  dp[1] = nums[0];
  for (int i = 2; i < n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  result = max(result, dp[n - 1]);
  return result;
}