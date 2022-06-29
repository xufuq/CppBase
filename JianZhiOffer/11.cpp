#include "../utils.h"

// 只对比右半部分
int minArray(vector<int>& numbers) {
  int n = numbers.size();
  int start = 0, end = n - 1, mid = (start + end) / 2;

  while (start < end) {
    if (numbers[mid] < numbers[end]) {
      end = mid;
    } else if (numbers[mid] > numbers[end]) {
      start = mid + 1;
    } else {
      end -= 1;
    }
    mid = (start + end) / 2;
  }
  return numbers[start];
}