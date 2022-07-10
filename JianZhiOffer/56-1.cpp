#include "../utils.h"

vector<int> singleNumbers(vector<int>& nums) {
  int bit = 0;
  for (auto& n : nums) {
    bit ^= n;
  }
  int i = 0;
  for (; i < 32; ++i) {
    if ((bit >> i) & 1) {
      break;
    }
  }
  int a = 0, b = 0;
  for (auto& n : nums) {
    if ((n >> i) & 1) {
      a ^= n;
    } else {
      b ^= n;
    }
  }
  return {a, b};
}