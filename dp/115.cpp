#include "../utils.h"

int numDistinct(string s, string t) {
  int s_len = s.length(), t_len = t.length();
  if (s_len == 0 || t_len == 0) {
    return 0;
  }
  vector<vector<int>> dp(s_len, vector<int>(t_len, 0));
  int count = 0;
  for (int i = 0; i < s_len; ++i) {
    if (s[i] == t[0]) {
      ++count;
    }
    dp[i][0] = count;
  }
  for (int i = 1; i < s_len; ++i) {
    for (int j = 1; j < t_len; ++j) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
}

int main() {
  cout << numDistinct("rabbbit", "rabbit");
  return 0;
}