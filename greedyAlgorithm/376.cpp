#include "../utils.h"
/*
int wiggleMaxLength(vector<int>& nums, int pre_num, int pre_sign,
                    int start_index, vector<vector<int>>& mem) {
  if (start_index >= nums.size()) {
    return 0;
  }
  int result = 0;
  if (pre_sign == 0) {
    if (pre_num > nums[start_index]) {
      if (mem[start_index][-1 + 1] == -1) {
        mem[start_index][-1 + 1] =
            1 +
            wiggleMaxLength(nums, nums[start_index], -1, start_index + 1, mem);
      }
      result = mem[start_index][-1 + 1];
    } else if (pre_num < nums[start_index]) {
      if (mem[start_index][1 + 1] == -1) {
        mem[start_index][1 + 1] = 1 + wiggleMaxLength(nums, nums[start_index],
                                                      1, start_index + 1, mem);
      }
      result = mem[start_index][1 + 1];
    }
    if (mem[start_index][0 + 1] == -1) {
      mem[start_index][0 + 1] =
          wiggleMaxLength(nums, pre_num, 0, start_index + 1, mem);
    }
    result = max(result, mem[start_index][0 + 1]);
  } else if (pre_sign == -1) {
    result = wiggleMaxLength(nums, pre_num, -1, start_index + 1, mem);
    if (nums[start_index] > pre_num) {
      if (mem[start_index][1 + 1] == -1) {
        mem[start_index][1 + 1] = 1 + wiggleMaxLength(nums, nums[start_index],
                                                      1, start_index + 1, mem);
      }
    }
    result = max(result, mem[start_index][1 + 1]);
  } else {
    result = wiggleMaxLength(nums, pre_num, 1, start_index + 1, mem);
    if (nums[start_index] < pre_num) {
      if (mem[start_index][-1 + 1] == -1) {
        mem[start_index][-1 + 1] =
            1 +
            wiggleMaxLength(nums, nums[start_index], -1, start_index + 1, mem);
      }
      result = max(result, mem[start_index][-1 + 1]);
    }
  }
  return result;
}

int wiggleMaxLength(vector<int>& nums) {
  vector<vector<int>> mem(nums.size(), vector<int>(3, -1));
  return 1 + wiggleMaxLength(nums, nums[0], 0, 1, mem);
}
*/

int wiggleMaxLength(vector<int>& nums) {}