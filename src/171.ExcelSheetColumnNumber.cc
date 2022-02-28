#include "headers.h"

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) {
      int d = c - 'A' + 1;
      result = result * 26 + d;
    }

    return result;
  }
};

TEST(ExcelSheetColumnNumber, ExcelSheetColumnNumber_1) {
  Solution s;
  string in = "FXSHRXW";
  cout << INT_MAX <<endl;
  int ans = 2147483647;
  EXPECT_EQ(s.titleToNumber(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}