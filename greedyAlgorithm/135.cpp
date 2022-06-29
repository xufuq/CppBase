#include "../utils.h"

int candy(vector<int>& ratings) {
  int n = ratings.size();
  vector<int> count(ratings.size(), 1);
  for (int i = 1; i < n; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      count[i] = count[i - 1] + 1;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (ratings[i] > ratings[i + 1]) {
      count[i] = max(count[i], count[i + 1] + 1);
    }
  }
  return accumulate(count.begin(), count.end(), 0);
}