#include "utils.h"

int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> vec;
  int start_index = 0;
  int result = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (vec.count(s[i]) && vec[s[i]] >= start_index) {
      start_index = vec[s[i]] + 1;
    }
    vec[s[i]] = i;
    result = max(i - start_index + 1, result);
  }
  return result;
}