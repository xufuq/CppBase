#include "../utils.h"

int maxProfit(int k, vector<int>& prices) {
  int n = prices.size();
  if (n == 0) {
    return 0;
  }
  vector<int> dp(2 * k + 1, 0);
  for (int i = 1; i < 2 * k + 1; i += 2) {
    dp[i] = -prices[0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < 2 * k + 1; j += 2) {
      dp[j] = max(dp[j], dp[j - 1] - prices[i]);
      dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
    }
  }
  int result = 0;
  for (int i = 2; i < 2 * k + 1; i += 2) {
    result = max(result, dp[i]);
  }
  return result;
}