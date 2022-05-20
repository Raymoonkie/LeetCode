#include "headers.h"

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    // return dfs(grid, 0, 0, m, n, dp);

    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          dp[i][j] = 0;
        } else {
          if (i > 0 && !grid[i - 1][j]) {
            dp[i][j] += dp[i - 1][j];
          }

          if (j > 0 && !grid[i][j - 1]) {
            dp[i][j] += dp[i][j - 1];
          }
        }
      }
    }

    return dp[m - 1][n - 1];
  }

  int dfs(vector<vector<int>>& grid, int i, int j, int m, int n,
          vector<vector<int>>& dp) {
    if (i >= m || j >= n || grid[i][j]) return 0;
    if (i == m - 1 && j == n - 1) return 1;

    if (dp[i][j] > 0) return dp[i][j];

    int right = dfs(grid, i, j + 1, m, n, dp);
    int down = dfs(grid, i + 1, j, m, n, dp);

    dp[i][j] = right + down;

    return dp[i][j];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(UniquePath, UniquePath_1) {
  Solution s;
  vector<vector<int>> in = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int ans = 2;
  EXPECT_EQ(s.uniquePathsWithObstacles(in), ans);
}

TEST(UniquePath, UniquePath_2) {
  Solution s;
  vector<vector<int>> in = {{0, 1}, {0, 0}};
  int ans = 1;
  EXPECT_EQ(s.uniquePathsWithObstacles(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}