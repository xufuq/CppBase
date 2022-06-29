#include "../utils.h"

int maxProfit(vector<int>& prices, int fee) {
  int buy_in = 50001;
  int profit = 0;
  int n = prices.size();
  for (int i = 0; i < n; ++i) {
    if (prices[i] > (buy_in + fee)) {
      profit += prices[i] - buy_in - fee;
      buy_in = prices[i] - fee;
    } else if (prices[i] < buy_in) {
      buy_in = prices[i];
    }
  }
  return profit;
}