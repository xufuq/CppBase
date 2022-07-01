#include "utils.h"

bool LessThan(int lhs, int rhs) {
  string lstr = to_string(lhs), rstr = to_string(rhs);
  return (lstr + rstr) < (rstr + lstr);
}

string minNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end(), LessThan);
  std::string result;
  for (auto& n : nums) {
    result += to_string(n);
  }
  return result;
}