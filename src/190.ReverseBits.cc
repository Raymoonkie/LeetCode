#include "headers.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
          ans <<=1;
          ans = ans | (n &1);
          n >>=1;
        }

      return ans;
    }
};

TEST(ReverseBits, ReverseBits_1) {
  Solution s;
  uint32_t in = 43261596;
  int ans = 964176192;
  EXPECT_EQ(s.reverseBits(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}