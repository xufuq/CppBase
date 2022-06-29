#include "../utils.h"

int evalRPN(vector<string>& tokens) {
  stack<int> st;
  for (auto& str : tokens) {
    if (str == "+") {
      int num2 = st.top();
      st.pop();
      int num1 = st.top();
      st.pop();
      num1 += num2;
      st.push(num1);
    } else if (str == "-") {
      int num2 = st.top();
      st.pop();
      int num1 = st.top();
      st.pop();
      num1 -= num2;
      st.push(num1);
    } else if (str == "*") {
      int num2 = st.top();
      st.pop();
      int num1 = st.top();
      st.pop();
      num1 *= num2;
      st.push(num1);
    } else if (str == "/") {
      int num2 = st.top();
      st.pop();
      int num1 = st.top();
      st.pop();
      num1 /= num2;
      st.push(num1);
    } else {
      st.push(atoi(str.data()));
    }
  }
  return st.top();
}