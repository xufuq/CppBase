#include "../utils.h"

int nthUglyNumber(int n) {
  vector<int> dp(n + 1);
  dp[1] = 1;
  int p2 = 1, p3 = 1, p5 = 1;
  int n2, n3, n5;
  for (int i = 2; i <= n; ++i) {
    n2 = dp[p2] * 2;
    n3 = dp[p3] * 3;
    n5 = dp[n5] * 5;
    int num = min(n2, min(n3, n5));
    if (n2 == num) {
      ++p2;
    }
    if (n3 == num) {
      ++n3;
    }
    if (n5 == num) {
      ++n5;
    }
    dp[i] = num;
  }
  return dp[n];
}