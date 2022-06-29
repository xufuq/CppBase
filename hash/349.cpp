#include "../utils.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> num_set;
  vector<int> result;
  for (auto& n : nums1) {
    num_set.insert(n);
  }
  for (auto& n : nums2) {
    if (num_set.count(n) == 1) {
      result.push_back(n);
      num_set.erase(n);
    }
  }
  return result;
}