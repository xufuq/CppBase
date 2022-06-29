#include "../utils.h"

int removeElement(vector<int>& nums, int val) {
  if (nums.size() == 0) {
    return 0;
  }
  int first = 0, second = nums.size() - 1;
  while (first <= second) {
    if (nums[first] == val) {
      if (nums[second] == val) {
        --second;
      } else {
        nums[first] = nums[second];
        ++first;
        --second;
      }
    } else {
      ++first;
    }
  }
  return second + 1;
}