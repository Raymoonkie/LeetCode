#include "headers.h"

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int r = 0;
    int c = n - 1;

    while (r < m && c >= 0) {
      if (matrix[r][c] == target) return true;

      matrix[r][c] > target ? c-- : r++;
    }

    return false;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(Search2DMatrix, Search2DMatrix_1) {
  Solution s;
  vector<vector<int>> in = {{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}};
  EXPECT_EQ(s.searchMatrix(in, 20), false);
  EXPECT_EQ(s.searchMatrix(in, 21), true);
  EXPECT_EQ(s.searchMatrix(in, 1), true);
}

TEST(Search2DMatrix, Search2DMatrix_2) {
  Solution s;
  vector<vector<int>> in = {{-5}};
  EXPECT_EQ(s.searchMatrix(in, -5), true);
  EXPECT_EQ(s.searchMatrix(in, -10), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}