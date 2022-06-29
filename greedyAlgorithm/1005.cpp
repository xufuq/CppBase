#include "../utils.h"

int largestSumAfterKNegations(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    if (k > 0) {
      if (nums[i] < 0) {
        nums[i] = -nums[i];
        --k;
      } else if (nums[i] == 0) {
        return accumulate(nums.begin(), nums.end(), 0);
      } else {
        break;
      }
    } else {
      break;
    }
  }
  if (k != 0 && k % 2 == 1) {
    sort(nums.begin(), nums.end());
    nums[0] = -nums[0];
  }
  return accumulate(nums.begin(), nums.end(), 0);
}