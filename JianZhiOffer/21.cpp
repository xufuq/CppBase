#include "../utils.h"

vector<int> exchange(vector<int>& nums) {
  if (nums.size() == 0) {
    return nums;
  }
  int left = 0, right = nums.size() - 1;
  int cur = nums[0];
  while (left <= right) {
    if (cur % 2 == 0) {
      int tmp = nums[right];
      nums[right] = cur;
      cur = tmp;
      --right;
    } else {
      nums[left] = cur;
      ++left;
      if (left <= right) {
        cur = nums[left];
      }
    }
  }

  return nums;
}