#include "headers.h"

class Solution {
 public:
  int getSum(int a, int b) {
    int c = 0;
    while (b) {
      c = a & b;
      a = a ^ b;
      b = (c & 0xffffffff) << 1;
    }

    return a;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SumOfTwoInteger, SumOfTwoInteger_1) {
  Solution s;
  EXPECT_EQ(s.getSum(1, 2), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}