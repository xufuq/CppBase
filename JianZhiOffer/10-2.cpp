#include "../utils.h"

int numWays(int n) {
  int base = 1000000007;
  if (n < 2) {
    return 1;
  }
  vector<int> dp(2, 1);
  int tmp = dp[1];
  for (int i = 2; i <= n; ++i) {
    tmp = dp[1] % base;
    dp[1] += dp[0];
    dp[1] %= base;
    dp[0] = tmp;
  }
  return dp[1];
}