#include "../utils.h"

bool isValid(string s) {
  stack<char> st;
  for (auto &c : s) {
    if (c == '(') {
      st.push(')');
    } else if (c == '[') {
      st.push(']');
    } else if (c == '{') {
      st.push('}');
    } else if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      return false;
    }
  }
  return st.empty();
}