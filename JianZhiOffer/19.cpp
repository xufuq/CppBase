#include "../utils.h"

// dp,能匹配的情况下，*也可以取0
bool isMatch(string s, string p) {
  int s_len = s.length(), p_len = p.length();
  vector<vector<bool>> dp(p_len + 1, vector<bool>(s_len + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < p_len; ++i) {
    if (p[i] == '*') {
      dp[i + 1][0] = dp[i - 1][0];
    }
  }
  for (int i = 0; i < p_len; ++i) {
    for (int j = 0; j < s_len; ++j) {
      if (s[j] == p[i] || p[i] == '.') {
        dp[i + 1][j + 1] = dp[i][j];
      } else if (p[i] == '*') {
        if (p[i - 1] == s[j] || p[i - 1] == '.') {
          dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i - 1][j + 1];
        } else {
          dp[i + 1][j + 1] = dp[i - 1][j + 1];
        }
      }
    }
  }
  return dp[p_len][s_len];
}