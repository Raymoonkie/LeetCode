#include "headers.h"

class MedianFinder {
  priority_queue<int> first;                              // max heap
  priority_queue<int, vector<int>, greater<int>> second;  // min heap

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (first.empty() || num < first.top()) {
      first.push(num);
    } else {
      second.push(num);
    }

    // balance
    if (first.size() > second.size() + 1) {
      second.push(first.top());
      first.pop();
    }

    if (second.size() > first.size() + 1) {
      first.push(second.top());
      second.pop();
    }
  }

  double findMedian() {
    if (first.size() == second.size())
      return (first.top() + second.top()) / 2.0;
    else
      return first.size() > second.size() ? first.top() : second.top();
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FindMedianFromDataStream, FindMedianFromDataStream_1) {
  MedianFinder* medianFinder = new MedianFinder();
  medianFinder->addNum(1);                     // arr = [1]
  medianFinder->addNum(2);                     // arr = [1, 2]
  EXPECT_EQ(medianFinder->findMedian(), 1.5);  // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder->addNum(3);                     // arr[1, 2, 3]
  EXPECT_EQ(medianFinder->findMedian(), 2.0);  // return 2.0
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}