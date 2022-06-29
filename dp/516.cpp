#include "../utils.h"

int longestPalindromeSubseq(string s) {
  int len = s.length();
  vector<vector<int>> dp(len, vector<int>(len, 0));
  for (int i = 0; i < len; ++i) {
    for (int j = i; j >= 0; --j) {
      if (j == i || j == i - 1) {
        if (s[i] == s[j]) {
          dp[i][j] = i - j + 1;
        } else {
          dp[i][j] = 1;
        }
      } else {
        if (s[i] == s[j]) {
          dp[i][j] = max(dp[i - 1][j + 1] + 2, max(dp[i][j + 1], dp[i - 1][j]));
        } else {
          dp[i][j] = max(dp[i - 1][j + 1], max(dp[i][j + 1], dp[i - 1][j]));
        }
      }
    }
  }
  return dp[len - 1][0];
}

int main(int argc, const char **argv) {
  cout << longestPalindromeSubseq(argv[1]) << endl;
  return 0;
}
