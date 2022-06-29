#include "../utils.h"

int lastStoneWeightII(vector<int>& stones) {
  int sum = accumulate(stones.begin(), stones.end(), 0);
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  for (auto& st : stones) {
    for (int i = target; i >= st; --i) {
      dp[i] = max(dp[i], dp[i - st] + st);
    }
  }
  return sum - 2 * dp.back();
}