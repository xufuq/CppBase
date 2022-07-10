#include "../utils.h"

int missingNumber(vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  int mid = (left + right) / 2;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] > mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}