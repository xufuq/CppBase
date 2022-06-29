#include "../utils.h"

int integerBreak(int n) {
  if (n == 2) {
    return 1;
  }
  vector<int> dp(n + 1, 1);
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i] = max(j * max(i - j, dp[i - j]), dp[i]);
    }
  }
  return dp[n];
}