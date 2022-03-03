#include "headers.h"

class Solution {
 public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(PowerOfThree, PowerOfThree_1) {
  Solution s;

  for (int i = 0; i < 19; i++) {
    EXPECT_EQ(s.isPowerOfThree(pow(3, i)), true);
    EXPECT_EQ(s.isPowerOfThree(pow(3, i) + 1), false);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}