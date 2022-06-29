#include "../utils.h"

bool twoSplit(vector<int>& nums, int target, int start, int end) {
  int mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size(), last_i = INT32_MIN, last_j = INT32_MIN;
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());  // 升序
  for (int i = 0; i < n; ++i) {
    if (nums[i] > 0) {
      break;
    } else if (last_i == nums[i]) {
      continue;
    } else {
      last_i = nums[i];
    }
    last_j = INT32_MIN;
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] > 0) {
        break;
      } else if (last_j == nums[j]) {
        continue;
      } else {
        last_j = nums[j];
      }
      if (twoSplit(nums, -nums[i] - nums[j], j + 1, n - 1)) {
        result.push_back({nums[i], nums[j], -nums[i] - nums[j]});
      }
    }
  }
  return result;
}