#include "utils.h"

int maxProfit(vector<int>& prices) {
  int result = 0;
  int min_val = INT32_MAX;
  for (auto& c : prices) {
    min_val = min(c, min_val);
    result = max(result, c - min_val);
  }
  return result;
}