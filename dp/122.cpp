#include "../utils.h"

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  // 0表示买入状态，1表示不买入状态
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  return dp[n - 1][1];
}

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  // 0表示买入状态，1表示不买入状态
  vector<vector<int>> dp(2, vector<int>(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < n; ++i) {
    dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
    dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
  }
  return dp[(n - 1) % 2][1];
}