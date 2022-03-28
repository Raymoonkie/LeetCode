#include "headers.h"

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bool first_col_has_zero = false;
    bool first_row_has_zero = false;
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        first_col_has_zero = true;
        break;
      }
    }

    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        first_row_has_zero = true;
        break;
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (first_col_has_zero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }

    if (first_row_has_zero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SetMatrixZeroes, SetMatrixZeroes_1) {
  Solution s;
  vector<vector<int>> in = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> ans = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

  s.setZeroes(in);
  EXPECT_EQ(in, ans);
}

TEST(SetMatrixZeroes, SetMatrixZeroes_2) {
  Solution s;
  vector<vector<int>> in = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> ans = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};

  s.setZeroes(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}