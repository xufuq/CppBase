#include "../utils.h"

// 动态规划，逐个统计

vector<double> dicesProbability(int n) {
  vector<vector<double>> dp(n);
  {
    vector<double> tmp(6, 0);
    for (int i = 0; i < 6; ++i) {
      tmp[i] = 1.0 / 6;
    }
    dp.push_back(tmp);
  }
  for (int i = 1; i < n; ++i) {
    int count = (i + 1) * 5 + 1;
    vector<double> tmp(count, 0);
    for (int j = 0; j < count; ++j) {
      for (int k = 0; k < 6; ++k) {
        if (j - k >= 0 && j - k < dp.back().size()) {
          tmp[j] += 1.0 / 6 * dp.back()[j - k];
        }
      }
    }
    dp.push_back(tmp);
  }
  return dp.back();
}