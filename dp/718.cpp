#include "../utils.h"

int findLength(vector<int>& nums1, vector<int>& nums2) {
  int result = 0;
  int n1 = nums1.size(), n2 = nums2.size();
  vector<vector<int>> dp(n1, vector<int>(n2, 0));
  for (int i = 0; i < n2; ++i) {
    dp[0][i] = nums1[0] == nums2[i];
    result = max(result, dp[0][i]);
  }
  for (int i = 0; i < n1; ++i) {
    dp[i][0] = nums1[i] == nums2[0];
    result = max(result, dp[i][0]);
  }
  for (int i = 1; i < n1; ++i) {
    for (int j = 1; j < n2; ++j) {
      if (nums1[i] == nums2[j]) {
        dp[i][j] += dp[i - 1][j - 1] + 1;
        result = max(result, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return result;
}