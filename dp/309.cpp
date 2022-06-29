#include "../utils.h"

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  if (n < 2) {
    return 0;
  }
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = -prices[0];
  dp[1][0] = max(dp[0][0], -prices[1]);
  dp[1][1] = max(dp[1][0], dp[1][0] + prices[1]);
  for (int i = 2; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  return max(dp[n - 1][1], dp[n - 2][1]);
}