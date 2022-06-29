#include "../utils.h"

vector<int> sortedSquares(vector<int>& nums) {
  int left = 0, right = nums.size() - 1, n = nums.size();
  vector<int> results(n);
  while (left <= right) {
    if (nums[left] * nums[left] > nums[right] * nums[right]) {
      results[--n] = nums[left] * nums[left];
      ++left;
    } else {
      results[--n] = nums[right] * nums[right];
      --right;
    }
  }
  return results;
}