#include "../utils.h"

// 一个大根堆放较小的元素
// 一个小根堆放较大的元素

struct MoreQueCmp {
  bool operator()(int lhs, int rhs) { return lhs > rhs; }
};

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (more_root.size() == little_root.size()) {
      little_root.push(num);
      int top = little_root.top();
      little_root.pop();
      more_root.push(top);
    } else {
      more_root.push(num);
      int top = more_root.top();
      more_root.pop();
      little_root.push(top);
    }
  }

  double findMedian() {
    if (more_root.empty() && little_root.empty()) {
      return 0;
    }
    if (more_root.size() > little_root.size()) {
      return more_root.top();
    } else if (more_root.size() < little_root.size()) {
      return little_root.top();
    } else {
      return (more_root.top() + little_root.top()) / 2.0;
    }
  }

 private:
  priority_queue<int, vector<int>, MoreQueCmp> little_root;
  priority_queue<int> more_root;
};
