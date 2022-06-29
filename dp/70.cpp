#include "../utils.h"

int climbStairs(int n) {
  if (n == 1) {
    return 1;
  }
  vector<int> dp(3, 1);
  for (int i = 2; i <= n; ++i) {
    dp[2] = dp[0] + dp[1];
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  return dp[2];
}