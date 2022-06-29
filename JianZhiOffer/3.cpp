#include "../utils.h"

int findRepeatNumber(vector<int>& nums) {
  unordered_set<int> n_set;
  for (auto& n : nums) {
    if (n_set.count(n) == 1) {
      return n;
    } else {
      n_set.insert(n);
    }
  }
}