#include "headers.h"

class Solution {
 public:
  int backup[50];
  int climbStairs(int n) {
    prepare();

    return backup[n];
  }

  void prepare() {
    backup[0] = 0;
    backup[1] = 1;
    backup[2] = 2;

    for(int i = 3; i <= 45; i ++) {
      backup[i] = backup[i-1] + backup[i-2]; 
    }
  }
};

TEST(climbingStairs, climbingStairs_1) {
  Solution s;
  int in = 1;

  int ans = 1;
  EXPECT_EQ(s.climbStairs(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}