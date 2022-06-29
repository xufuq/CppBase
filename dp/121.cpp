#include "../utils.h"

int maxProfit(vector<int>& prices) {
  int min_pric = INT32_MAX;
  int result = 0;
  for (auto& p : prices) {
    result = max(result, p - min_pric);
    min_pric = min(min_pric, p);
  }
  return result;
}

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  // 0买入股票状态，1未买入股票状态
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = -prices[0];
  dp[0][1] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
  }
  return dp[n - 1][1];
}