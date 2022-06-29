#include "../utils.h"

int trap(vector<int>& height) {
  int base = 0, result = 0, n = height.size();
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    if (height[i] == 0) {
      continue;
    }
    base = 0;
    while ((!st.empty()) && height[i] >= height[st.top()]) {
      result += (i - st.top() - 1) * (height[st.top()] - base);
      base = height[st.top()];
      st.pop();
      cout << "(while: " << result << ") ";
    }
    if (!st.empty()) {
      cout << "(add: " << height[i] << " " << base << " ";
      result += (i - st.top() - 1) * (height[i] - base);
    }
    st.push(i);
    cout << "(push: " << result << ")" << endl;
  }
  return result;
}