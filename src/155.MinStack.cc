#include "headers.h"

class MinStack {
  vector<int> data;
  int min = INT32_MAX;

 public:
  MinStack() {}

  void push(int val) {
    if (val <= min) {
      data.push_back(min);
      min = val;
    }

    data.push_back(val);
  }

  void pop() {
    if (data.back() == min) {
      data.pop_back();
      min = data.back();
    }
    data.pop_back();
  }

  int top() { return data.back(); }

  int getMin() { return min; }
};

TEST(MinStack, MinStack_1) {
  MinStack minStack = MinStack();
  minStack.push(2);
  minStack.push(0);
  minStack.push(3);
  minStack.push(0);
  EXPECT_EQ(0, minStack.getMin());
  minStack.pop();
  EXPECT_EQ(0, minStack.getMin());
  minStack.pop();
  EXPECT_EQ(0, minStack.getMin());
  minStack.pop();
  EXPECT_EQ(2, minStack.getMin());
  minStack.pop();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}