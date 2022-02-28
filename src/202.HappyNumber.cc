#include "headers.h"

class Solution {
 public:
  bool isHappy(int n) {
    int fast = n, slow = n;

    do {
      slow = squareSum(slow);
      fast = squareSum(fast);
      fast = squareSum(fast);
    } while (fast != slow);

    return fast == 1 ? 1 : 0;
  }

  int squareSum(int n) {
    int sum = 0;
    while (n > 0) {
      int tmp = n % 10;
      sum += tmp * tmp;
      n /= 10;
    }

    return sum;
  }
};

TEST(HappyNumber, HappyNumber_1) {
  Solution s;
  int in = 19;
  int ans = 1;
  EXPECT_EQ(s.isHappy(in), ans);
}

TEST(HappyNumber, HappyNumber_2) {
  Solution s;
  int in = 2;
  int ans = 0;
  EXPECT_EQ(s.isHappy(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}