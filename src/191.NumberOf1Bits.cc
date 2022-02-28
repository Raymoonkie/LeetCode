#include "headers.h"

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int c = 0;
    for (int i = 0; i < 32; i++) {
      if (n & 1) {
        c++;
      }

      n >>= 1;
    }

    return c;
  }
};

TEST(NumberOf1Bits, NumberOf1Bits_1) {
  Solution s;
  int in = 11;
  int ans = 3;
  EXPECT_EQ(s.hammingWeight(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}