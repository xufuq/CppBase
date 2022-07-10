#include "../utils.h"

// 逆序对的总数
int result = 0;
bool mergeSort(vector<int>& nums, int start, int end) {
  if (start >= end - 1) {
    return true;
  }
  int mid = (start + end) / 2;
  mergeSort(nums, start, mid);
  mergeSort(nums, mid, end);
  vector<int> tmp(end - start, 0);
  int left = start, right = mid;
  int i = 0;
  for (; i < end - start; ++i) {
    if (left < mid && right < end) {
      if (nums[left] <= nums[right]) {
        tmp[i] = nums[left];
        ++left;
        result += right - mid;
      } else {
        tmp[i] = nums[right];
        ++right;
      }
    } else if (left < mid) {
      tmp[i] = nums[left];
      ++left;
      result += right - mid;
    } else {
      tmp[i] = nums[right];
      ++right;
    }
  }
  for (i = 0; i < end - start; ++i) {
    nums[start + i] = tmp[i];
  }
  return true;
}

int reversePairs(vector<int>& nums) {
  mergeSort(nums, 0, nums.size());
  return result;
}
