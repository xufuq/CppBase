#include "../utils.h"

string removeDuplicates(string s) {
  stack<char> st;
  for (auto &c : s) {
    if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      st.push(c);
    }
  }
  string result;
  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}