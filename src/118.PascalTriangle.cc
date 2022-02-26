#include "headers.h"

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans = vector<vector<int>>(numRows);
    ans[0] = {1};
    for (int i = 1; i < numRows; i++) {
      vector<int> row = vector<int>(i + 1);
      row[0] = 1;
      row[i] = 1;
      for (int j = 1; j < i; j++) {
        row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
      }
      ans[i] = row;
    }

    return ans;
  }
};

TEST(PascalTriangle, PascalTriangle_1) {
  Solution s;
  vector<vector<int>> expect = {
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};

  vector<vector<int>> ans = s.generate(5);
  EXPECT_EQ(expect, ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}