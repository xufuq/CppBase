#include "../utils.h"

int findTargetSumWays(vector<int>& nums, int target) {
  int n = nums.size();
  vector<unordered_map<int, int>> dp(n);
  ++dp[0][nums[0]];
  ++dp[0][-nums[0]];
  for (int i = 1; i < n; ++i) {
    for (auto& m : dp[i - 1]) {
      dp[i][-nums[i] + m.first] += m.second;
      dp[i][nums[i] + m.first] += m.second;
    }
  }
  return dp.back()[target];
}