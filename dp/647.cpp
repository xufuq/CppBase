#include "../utils.h"

int countSubstrings(string s) {
  int len = s.length(), result = 0;
  vector<vector<bool>> dp(len, vector<bool>(len, false));
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == i || j == i - 1) {
        if (s[j] == s[i]) {
          dp[i][j] = true;
          ++result;
        }
      } else if (s[j] == s[i] && dp[i - 1][j + 1]) {
        dp[i][j] = true;
        ++result;
      }
    }
  }
  return result;
}
