#include "headers.h"

class Solution {
 public:
  bool isPalindrome(string s) {
    int p = 0;
    int q = s.length() - 1;

    while (p < q) {
      if (!isalnum(s[p])) {
        p++;
      } else if (!isalnum(s[q])) {
        q--;
      } else {
        if (tolower(s[p]) == tolower(s[q])) {
          p++;
          q--;
        } else {
          return false;
        }
      }
    }

    return true;
  }
};

TEST(ValidPalindrome, ValidPalindrome_1) {
  Solution s;
  string in = "A man, a plan, a canal: Panama";
  EXPECT_EQ(s.isPalindrome(in), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}