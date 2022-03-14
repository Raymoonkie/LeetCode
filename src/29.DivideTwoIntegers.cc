#include "headers.h"

class Solution {
 public:
  int divide(int A, int B) {
    if (A == INT_MIN && B == -1) return INT_MAX;

    unsigned int a = abs(A);
    unsigned int b = abs(B);
    unsigned int res = 0;

    for (int x = 31; x >= 0; x--) {
      if ((a >> x) >= b) {
        a = a - (b << x);
        res = res + (1 << x);
      }
    }

    return (A > 0) == (B > 0) ? res : -res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(DivideTwoIntegers, DivideTwoIntegers_1) {
  Solution s;
  int A = 10;
  int B = 3;
  int ans = 3;
  EXPECT_EQ(s.divide(A, B), ans);
}

TEST(DivideTwoIntegers, DivideTwoIntegers_2) {
  Solution s;
  int A = 7;
  int B = -3;
  int ans = -2;
  EXPECT_EQ(s.divide(A, B), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}