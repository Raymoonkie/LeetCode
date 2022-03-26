#include "headers.h"

class Solution {
 public:
  double myPow(double x, int n) {
    double res = 1;
    while (n) {
      if (n % 2) res = n > 0 ? res * x : res / x;
      x *= x;
      n /= 2;
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(Pow, Pow_1) {
  Solution s;
  double in = 2.0000;
  int n = 10;
  double ans = 1024.0000;
  EXPECT_DOUBLE_EQ(s.myPow(in, n), ans);
}

TEST(Pow, Pow_2) {
  Solution s;
  double in = 2.1000;
  int n = 3;
  double ans = 9.2610;
  EXPECT_DOUBLE_EQ(s.myPow(in, n), ans);
}

TEST(Pow, Pow_3) {
  Solution s;
  double in = 2.0000;
  int n = -2;
  double ans = 0.25;
  EXPECT_DOUBLE_EQ(s.myPow(in, n), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}