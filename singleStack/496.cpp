#include "../utils.h"

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> n1_map;
  for (int i = 0; i < nums1.size(); ++i) {
    n1_map[nums1[i]] = i;
  }
  stack<int> st;
  for (int i = 0; i < nums2.size(); ++i) {
    while ((!st.empty()) && st.top() < nums2[i]) {
      if (n1_map.count(st.top())) {
        nums1[n1_map[st.top()]] = nums2[i];
      }
      st.pop();
    }
    st.push(nums2[i]);
  }
  while (!st.empty()) {
    if (n1_map.count(st.top())) {
      nums1[n1_map[st.top()]] = -1;
    }
    st.pop();
  }
  return nums1;
}