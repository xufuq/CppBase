#include "utils.h"
int translateNum(int num) {
  int dp[2] = {1, 1};
  string str = to_string(num);
  for (int i = 1; i < str.length(); ++i) {
    int tmp = dp[1];
    if (str[i - 1] != '0' && ((str[i - 1] - '0') * 10 + str[i] - '0' < 26)) {
      tmp += dp[0];
    }
    dp[0] = dp[1];
    dp[1] = tmp;
  }
  return dp[1];
}