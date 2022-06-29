#include "../utils.h"

int majorityElement(vector<int>& nums) {
  unordered_map<int, int> counts;
  int result = nums[0];
  for (auto& n : nums) {
    ++counts[n];
    if (counts[n] > counts[result]) {
      result = n;
    }
  }
  return result;
}