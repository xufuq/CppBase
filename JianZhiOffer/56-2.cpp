#include "../utils.h"

int singleNumber(vector<int>& nums) {
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    int bit_1 = 0;
    for (auto& n : nums) {
      if ((n >> i) & 1) {
        ++bit_1;
      }
    }
    if (bit_1 % 3) {
      result |= 1 << i;
    }
  }
  return result;
}