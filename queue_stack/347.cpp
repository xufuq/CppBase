#include "../utils.h"

struct cmp {
  bool operator()(pair<int, int>& left, pair<int, int>& right) {
    return (left.second > right.second);
  }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> count;
  for (auto& n : nums) {
    ++count[n];
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que{count.begin(),
                                                                  count.end()};
  vector<int> result(k);
  while (k > 0) {
    result[k - 1] = que.top().first;
    que.pop();
    --k;
  }
  return result;
}