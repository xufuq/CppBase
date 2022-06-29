#include "../utils.h"

bool canPartition(vector<int>& nums) {
  // size sum/2
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 == 1) {
    return false;
  }
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  for (auto& n : nums) {
    for (int i = target; i >= n; --i) {
      dp[i] = max(dp[i], dp[i - n] + n);
    }
  }
  return dp.back() == target;
}