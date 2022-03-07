#include "headers.h"

class Solution {
 public:
  int reverse(int x) {
    if (x == INT_MIN || x == INT_MAX) {
      return 0;
    }

    bool negative = x < 0;
    if (negative) {
      x = -x;
    }

    int ans = 0;
    while (x > 0) {
      if (INT_MAX / 10 < ans) {
        return 0;
      }
      ans = ans * 10 + x % 10;
      x /= 10;
    }

    return negative ? -ans : ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ReverseInteger, ReverseInteger_1) {
  Solution s;
  int in = -321;
  int ans = -123;
  EXPECT_EQ(s.reverse(in), ans);
}

TEST(ReverseInteger, ReverseInteger_2) {
  Solution s;
  int in = 120;
  int ans = 21;
  EXPECT_EQ(s.reverse(in), ans);
}

TEST(ReverseInteger, ReverseInteger_3) {
  Solution s;
  int in = 0;
  int ans = 0;
  EXPECT_EQ(s.reverse(in), ans);
}

TEST(ReverseInteger, ReverseInteger_4) {
  Solution s;
  int in = INT_MIN;
  int ans = 0;
  EXPECT_EQ(s.reverse(in), ans);
}

TEST(ReverseInteger, ReverseInteger_5) {
  Solution s;
  int in = INT_MAX;
  int ans = 0;
  EXPECT_EQ(s.reverse(in), ans);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}