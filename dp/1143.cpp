#include "../utils.h"

int longestCommonSubsequence(string text1, string text2) {
  int n1 = text1.length(), n2 = text2.length();
  // 使用一维数组挑战
  vector<int> dp(n2 + 1, 0);
  int pre = 0, cur = 0;
  for (int i = 0; i < n1; ++i) {
    pre = dp[0];
    for (int j = 0; j < n2; ++j) {
      cur = dp[j + 1];
      if (text1[i] == text2[j]) {
        dp[j + 1] = max(dp[j + 1], max(dp[j], pre + 1));
      } else {
        dp[j + 1] = max(dp[j + 1], dp[j]);
      }
      pre = cur;
    }
  }
  return dp[n2];
}