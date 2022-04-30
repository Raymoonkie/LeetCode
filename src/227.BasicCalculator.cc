#include "headers.h"

class Solution {
 public:
  int calculate(string s) {
    int val = 0;
    int ans = 0;
    int interRes = 0;

    s += "##";
    char prevOp = '+';
    for (int i = 0; i < s.length(); i++) {
      if (isspace(s[i]))
        continue;
      else if (isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
      } else {
        if (prevOp == '*') {
          interRes *= val;
        } else if (prevOp == '/') {
          interRes /= val;
        } else {
          ans += interRes;
          interRes = prevOp == '+' ? val : -val;
        }

        prevOp = s[i];
        val = 0;
      }
    }
    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(BasicCalculator, BasicCalculator_1) {
  Solution s;
  EXPECT_EQ(s.calculate("1+2*3"), 7);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}