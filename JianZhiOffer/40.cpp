#include "../utils.h"

vector<int> getLeastNumbers(vector<int>& arr, int k) {
  vector<int> result;
  if (k == 0) return result;
  priority_queue<int> que;
  for (auto& n : arr) {
    if (que.size() < k) {
      que.push(n);
    } else if (que.top() > n) {
      que.pop();
      que.push(n);
    }
  }
  while (!que.empty()) {
    result.push_back(que.top());
    que.pop();
  }
  return result;
}