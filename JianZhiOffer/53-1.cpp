#include "../utils.h"

int search(vector<int>& nums, int target) {
  int result = 0;
  for (auto& n : nums) {
    if (target == n) {
      ++result;
    }
  }
  return result;
}