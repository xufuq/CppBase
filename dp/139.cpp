#include "../utils.h"

bool wordBreak(string s, vector<string>& wordDict) {
  int len = s.length();
  vector<bool> dp(len + 1, false);
  dp[0] = true;
  for (int i = 1; i <= len; ++i) {
    for (auto& word : wordDict) {
      if (i >= word.length() && dp[i - word.length()] == true &&
          word.compare(s.substr(i - word.length(), word.length())) == 0) {
        dp[i] = true;
      }
    }
  }
  return dp[len];
}