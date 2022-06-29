#include "../utils.h"

int maxProfit(vector<int>& prices) {
  // 四维数组，0买入第一次，1第一次卖出状态，2买入第二次，3第二次卖出状态
  int n = prices.size();
  vector<vector<int>> dp(2, vector<int>(4, 0));
  dp[0][0] = -prices[0];
  dp[0][2] = -prices[0];
  for (int i = 1; i < n; ++i) {
    dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
    dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
    dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] - prices[i]);
    dp[i % 2][3] = max(dp[(i - 1) % 2][3], prices[i] + dp[(i - 1) % 2][2]);
  }
  return max(dp[(n - 1) % 2][1], dp[(n - 1) % 2][3]);
}