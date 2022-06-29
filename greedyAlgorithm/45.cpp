#include "../utils.h"

int jump(vector<int>& nums) {
  if (nums.size() == 1) {
    return 0;
  }
  int n = nums.size();
  vector<int> count(n, INT32_MAX);
  count[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= nums[i]; ++j) {
      if (i + j < n) {
        count[i + j] = min(count[i + j], count[i] + 1);
      }
    }
  }
  return count.back();
}

int jump(vector<int>& nums) {
  int last_end = -1, cur_end = 0;
  int farest = 0, cur_step = 0;
  int last_index = nums.size() - 1;
  while (farest < last_index) {
    for (int i = last_end + 1; i <= cur_end; ++i) {
      farest = max(farest, i + nums[i]);
    }
    last_end = cur_end;
    cur_end = farest;
    ++cur_step;
  }
  return cur_step;
}