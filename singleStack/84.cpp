#include "../utils.h"

// 在这个数及其之后的空白坐标，都是这个数
// 弹出的时候再计算最大值
int largestRectangleArea(vector<int>& heights) {
  int result = 0, n = heights.size();
  stack<int> st;  // 记录的是下标
  // vec.push(0);
  for (int i = 0; i < n; ++i) {
    int pre_index = i;
    while (!st.empty() && heights[st.top()] > heights[i]) {
      pre_index = st.top();
      result = max(result, (i - pre_index) * heights[pre_index]);
      st.pop();
    }
    if (st.empty() || heights[st.top()] < heights[i]) {
      heights[pre_index] = heights[i];
      st.push(pre_index);
    }  // else: 想等
  }
  while (!st.empty()) {
    result = max(result, (n - st.top()) * heights[st.top()]);
    st.pop();
  }
  return result;
}