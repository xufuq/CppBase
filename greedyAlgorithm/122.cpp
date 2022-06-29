#include "../utils.h"

int maxProfit(vector<int>& prices) {
  int buy_in = INT32_MAX, profit = 0;
  int n = prices.size();
  for (int i = 0; i < n; ++i) {
    if (prices[i] > buy_in) {
      if (i == n - 1 || prices[i + 1] < prices[i]) {
        profit += prices[i] - buy_in;
        buy_in = prices[i];
      }
    } else {
      buy_in = prices[i];
    }
  }
  return profit;
}