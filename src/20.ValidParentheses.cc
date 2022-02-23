#include "headers.h"

class Solution {
 public:
  bool isValid(string s) {
    if (s.length() % 2 != 0) {
      return false;
    }
    char stack[s.length()];
    int index = 0;
    for (int i = 0; i < s.length(); i++) {
      switch (s[i]) {
        case ')':
          if (index > 0 && stack[index - 1] == '(') {
            index--;
          } else {
            return false;
          }
          break;
        case ']':
          if (index > 0 && stack[index - 1] == '[') {
            index--;
          } else {
            return false;
          }
          break;
        case '}':
          if (index > 0 && stack[index - 1] == '{') {
            index--;
          } else {
            return false;
          }
          break;
        default:
          stack[index] = s[i];
          index++;
          break;
      }
    }

    return index == 0;
  }
};

TEST(ValidParentheses, ValidParentheses_1) {
  Solution s;
  string in = "()[]{}";
  bool ans = true;
  EXPECT_EQ(s.isValid(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}