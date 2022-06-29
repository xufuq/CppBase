#include "../utils.h"

int coinChange(vector<int>& coins, int amount) {
  vector<int> dp(amount + 1, INT32_MAX);
  dp[0] = 0;
  for (auto& c : coins) {
    for (int i = c; i <= amount; ++i) {
      if (dp[i - c] != INT32_MAX) {
        dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
  }
  return dp[amount] == INT32_MAX ? -1 : dp[amount];
}