#include "headers.h"

class Solution {
 public:
  int trailingZeroes(int n) {
    int zeroes = 0;
    while (n) {
      zeroes += n /= 5;
    }

    return zeroes;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FactorialTailingZeroes, FactorialTailingZeroes_1) {
  Solution s;
  EXPECT_EQ(s.trailingZeroes(3), 0);
  EXPECT_EQ(s.trailingZeroes(5), 1);
  EXPECT_EQ(s.trailingZeroes(0), 0);
  EXPECT_EQ(s.trailingZeroes(23), 4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}