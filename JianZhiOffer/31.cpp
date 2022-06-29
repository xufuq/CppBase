#include "../utils.h"

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  int j = 0;
  stack<int> st;
  for (int i = 0; i < pushed.size(); ++i) {
    while (!st.empty() && st.top() == popped[j]) {
      st.pop();
      ++j;
    }
    if (pushed[i] != popped[j]) {
      st.push(pushed[i]);
    } else {
      ++j;
    }
  }
  while (j < popped.size()) {
    if (popped[j] == st.top()) {
      ++j;
      st.pop();
    } else {
      return false;
    }
  }
  return true;
}