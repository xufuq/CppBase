#include "../utils.h"

vector<int> printNumbers(int n) {
  int count = 1;
  while (n > 0) {
    count *= 10;
    --n;
  }
  --count;
  vector<int> result(count, 0);
  iota(result.begin(), result.end(), 1);
  return result;
}