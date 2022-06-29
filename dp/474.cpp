#include "../utils.h"

int findMaxForm(vector<string>& strs, int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  int len = strs.size();
  vector<vector<int>> count(len, vector<int>(2, 0));
  for (int i = 0; i < len; ++i) {
    for (auto& c : strs[i]) {
      if (c == '0') {
        ++count[i][0];
      } else {
        ++count[i][1];
      }
    }
  }
  for (int i = 0; i < len; ++i) {
    for (int j = m; j >= count[i][0]; --j) {
      for (int k = n; k >= count[i][1]; --k) {
        dp[j][k] = max(dp[j][k], dp[j - count[i][0]][k - count[i][1]] + 1);
      }
    }
  }
  return dp[m][n];
}