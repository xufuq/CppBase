#include "../utils.h"

bool isStraight(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int count_0;
  int i = 0;
  while (i < 5 && nums[i] == 0) {
    ++i;
    ++count_0;
  }
  int pre_num = nums[i++];
  while (i < 5) {
    if (nums[i] == pre_num) {
      return false;
    } else if (nums[i] - pre_num > 1) {
      if (count_0 > nums[i] - pre_num - 1) {
        count_0 -= nums[i] - pre_num - 1;
      } else {
        return false;
      }
    }
    pre_num = nums[i];
    ++i;
  }
  return true;
}