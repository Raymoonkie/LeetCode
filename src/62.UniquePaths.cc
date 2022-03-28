#include "headers.h"

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int grid[m][n];

    for (int i = 0; i < m; i++) {
      grid[i][0] = 1;
    }

    for (int j = 0; j < n; j++) {
      grid[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
      }
    }

    return grid[m - 1][n - 1];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(UniquePaths, UniquePaths_1) {
  Solution s;
  int ans = 3;
  EXPECT_EQ(s.uniquePaths(3, 2), ans);
}

TEST(UniquePaths, UniquePaths_2) {
  Solution s;
  int ans = 28;
  EXPECT_EQ(s.uniquePaths(3, 7), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}