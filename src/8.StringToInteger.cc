#include "headers.h"

class Solution {
 public:
  int myAtoi(string s) {
    int len = s.length();

    bool negative = false;
    int ans = 0;
    int index = 0;

    while (index < len && s[index] == ' ') {
      index++;
    }

    if (index < len && (s[index] == '-' || s[index] == '+')) {
      negative = s[index] == '-';
      index++;
    }

    while (index < len && s[index] >= '0' && s[index] <= '9') {
      if (ans > INT_MAX / 10 ||
          (ans == INT_MAX / 10 && s[index] - '0' > INT_MAX % 10)) {
        return negative ? INT_MIN : INT_MAX;
      }
      ans = ans * 10 + (s[index] - '0');
      index++;
    }

    return negative ? -ans : ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(StringToInteger, StringToInteger_1) {
  Solution s;
  string in = "42";
  int ans = 42;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_2) {
  Solution s;
  string in = "        -42";
  int ans = -42;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_3) {
  Solution s;
  string in = "4193 with word";
  int ans = 4193;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_4) {
  Solution s;
  string in = "0032";
  int ans = 32;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_5) {
  Solution s;
  string in = "2147483647";
  int ans = 2147483647;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_6) {
  Solution s;
  string in = "-2147483648";
  int ans = -2147483648;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_7) {
  Solution s;
  string in = "3.1415926";
  int ans = 3;
  EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(StringToInteger, StringToInteger_8) {
  Solution s;
  string in = "-+12";
  int ans = 0;
  EXPECT_EQ(s.myAtoi(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}