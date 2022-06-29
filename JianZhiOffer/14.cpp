#include "../utils.h"

// dp
int cuttingRope(int n) {
  vector<int> dp(n + 1, 0);
  dp[2] = 1, dp[1] = 1;
  for (int i = 3; i <= n; ++i) {
    for (int j = 2; j <= (i / 2 + 1); ++j) {
      dp[i] = max(max(dp[i], j * dp[i - j]), j * (i - j));
    }
  }
  return dp[n];
}