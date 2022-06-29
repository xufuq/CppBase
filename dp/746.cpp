#include "../utils.h"

int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(3, 0);
  int n = cost.size();
  for (int i = 2; i <= n; ++i) {
    dp[2] = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  return dp[2];
}