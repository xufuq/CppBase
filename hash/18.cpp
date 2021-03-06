#include "../utils.h"

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> result;
  for (int i = 0; i < n - 3; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < n - 2; ++j) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }
      int L = j + 1, R = n - 1;
      while (L < R) {
        if (nums[L] + nums[R] == target - nums[i] - nums[j]) {
          result.push_back({nums[i], nums[j], nums[L], nums[R]});
          ++L, --R;
          while (L < R && nums[L] == nums[L - 1]) {
            ++L;
          }
          while (L < R && nums[R] == nums[R + 1]) {
            --R;
          }
        } else if (nums[L] + nums[R] > target - nums[i] - nums[j]) {
          --R;
        } else {
          ++L;
        }
      }
    }
  }
  return result;
}