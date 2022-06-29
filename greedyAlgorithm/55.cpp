#include "../utils.h"

bool canJump(vector<int>& nums) {
  if (nums.size() == 1) {
    return true;
  }
  int farest = 0;
  for (int i = 0; i < nums.size() && i <= farest; ++i) {
    farest = max(farest, i + nums[i]);
    if (farest >= nums.size() - 1) {
      return true;
    }
  }
  return false;
}