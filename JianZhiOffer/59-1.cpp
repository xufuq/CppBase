#include "../utils.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  if (nums.empty()) {
    return {};
  }
  deque<int> que;
  vector<int> result(nums.size() - k + 1, 0);
  int left = 0, right = 0;
  for (int i = 0; i < k; ++i) {
    while (!que.empty() && nums[que.back()] <= nums[i]) {
      que.pop_back();
    }
    que.push_back(i);
  }
  for (int i = 0; i < nums.size() - k; ++i) {
    result[i] = nums[que.front()];
    if (que.front() == i) {
      que.pop_front();
    }
    while (!que.empty() && nums[que.back()] <= nums[i + k]) {
      que.pop_back();
    }
    que.push_back(i + k);
  }
  result.back() = nums[que.front()];
  return result;
}