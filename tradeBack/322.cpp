#include "../utils.h"

int coinChange(vector<int>& coins, unordered_map<int, int>& coin_map,
               int amount) {
  if (amount == 0) {
    return 0;
  }
  if (coin_map.find(amount) != coin_map.end()) {
    return coin_map[amount];
  }
  coin_map[amount] = -1;
  for (int i = 0; i < coins.size(); ++i) {
    if (amount >= coins[i]) {
      int result = coinChange(coins, coin_map, amount - coins[i]);
      if (result != -1) {
        if (coin_map[amount] == -1) {
          coin_map[amount] = result + 1;
        } else {
          coin_map[amount] = min(result + 1, coin_map[amount]);
        }
      }
    }
  }
  return coin_map[amount];
}

int coinChange(vector<int>& coins, int amount) {
  unordered_map<int, int> coin_map;
  return coinChange(coins, coin_map, amount);
}
