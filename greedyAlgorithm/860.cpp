#include "../utils.h"

bool lemonadeChange(vector<int>& bills) {
  int count[2] = {0, 0};
  for (int i = 0; i < bills.size(); ++i) {
    if (bills[i] == 5) {
      ++count[0];
    } else if (bills[i] == 10) {
      if (count[0] > 0) {
        --count[0];
        ++count[1];
      } else {
        return false;
      }
    } else if (bills[i] == 20) {
      if (count[0] > 0 && count[1] > 0) {
        --count[0];
        --count[1];
      } else if (count[0] > 2) {
        count[0] -= 3;
      } else {
        return false;
      }
    }
  }
  return true;
}