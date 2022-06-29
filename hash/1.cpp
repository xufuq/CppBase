#include "../utils.h"

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> num_index;
  vector<int> result;
  for (int i = 0; i < nums.size(); ++i) {
    if (num_index.find(target - nums[i]) != num_index.end()) {
      result.push_back(num_index[target - nums[i]]);
      result.push_back(i);
      break;
    }
    num_index[nums[i]] = i;
  }
  return result;
}