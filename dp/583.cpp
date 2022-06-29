#include "../utils.h"

// 找最长相同子串
int minDistance(string word1, string word2) {
  int n1 = word1.length(), n2 = word2.length();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      if (word1[i] == word2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  return n1 + n2 - 2 * dp[n1][n2];
}