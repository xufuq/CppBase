#include "../utils.h"

bool isSubsequence(string s, string t) {
  int n1 = s.length(), n2 = t.length();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  return dp[n1][n2] == n1;
}