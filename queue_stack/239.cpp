#include "../utils.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<vector<int>> que;  // pos value
  int new_size = nums.size() - k + 1;
  vector<int> result(new_size);
  for (int i = 0; i < k; ++i) {
    while (!que.empty() && que.back()[1] <= nums[i]) {
      que.pop_back();
    }
    que.push_back({i, nums[i]});
  }
  for (int i = 0, n_k = k - 1; i < new_size; ++i, ++n_k) {
    while (!que.empty() && que.back()[1] <= nums[n_k]) {
      que.pop_back();
    }
    que.push_back({n_k, nums[n_k]});
    result[i] = que.front()[1];
    if (que.front()[0] == i) {
      que.pop_front();
    }
  }
  return result;
}