#include "../utils.h"

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                 vector<int> &nums4) {
  int result = 0;
  unordered_map<int, int> count1, count2, sum12, sum34;
  for (auto &n1 : nums1) {
    ++count1[n1];
  }
  for (auto &n2 : nums2) {
    ++count2[n2];
  }
  for (auto &n1 : count1) {
    for (auto &n2 : count2) {
      sum12[n1.first + n2.first] += n1.second * n2.second;
    }
  }
  count1.clear();
  count2.clear();
  for (auto &n3 : nums3) {
    ++count1[n3];
  }
  for (auto &n4 : nums4) {
    ++count2[n4];
  }
  for (auto &n1 : count1) {
    for (auto &n2 : count2) {
      sum34[n1.first + n2.first] += n1.second * n2.second;
    }
  }
  for (auto &s1 : sum12) {
    for (auto &s2 : sum34) {
      if (s1.first + s2.first == 0) {
        result += s1.second * s2.second;
      }
    }
  }
  return result;
}