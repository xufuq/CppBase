#include "../utils.h"

vector<int> dailyTemperatures(vector<int>& temperatures) {
  stack<int> st;
  int n = temperatures.size();
  vector<int> result(n, 0);
  for (int i = 0; i < n; ++i) {
    while ((!st.empty()) && temperatures[st.top()] < temperatures[i]) {
      result[st.top()] = i - st.top();
      st.pop();
    }
    st.push(i);
  }
  return result;
}