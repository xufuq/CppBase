#include "../utils.h"

vector<int> constructArr(vector<int>& a) {
  int n = a.size();
  if (n == 0) {
    return {};
  }
  vector<int> forward(n, 0), back(n, 0), result(n, 1);
  forward[0] = a[0];
  for (int i = 1; i < n - 1; ++i) {
    forward[i] = forward[i - 1] * a[i];
  }
  back[n - 1] = a[n - 1];
  for (int i = n - 2; i > 0; --i) {
    back[i] = back[i + 1] * a[i];
  }
  result[0] = back[1];
  result[n - 1] = forward[n - 2];
  for (int i = 1; i < n - 1; ++i) {
    result[i] = forward[i - 1] * back[i + 1];
  }
  return result;
}