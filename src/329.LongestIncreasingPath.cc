#include "headers.h"

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxP = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        maxP = max(maxP, dfs(matrix, i, j, -1, m, n, dp));
      }
    }

    return maxP;
  }

  int dfs(vector<vector<int>>& matrix, int i, int j, int prev, int m, int n,
          vector<vector<int>>& dp) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev) return 0;
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = 1 + max({
                              dfs(matrix, i + 1, j, matrix[i][j], m, n, dp),
                              dfs(matrix, i - 1, j, matrix[i][j], m, n, dp),
                              dfs(matrix, i, j + 1, matrix[i][j], m, n, dp),
                              dfs(matrix, i, j - 1, matrix[i][j], m, n, dp),
                          });
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestIncreasingPath, LongestIncreasingPath_1) {
  Solution s;
  vector<vector<int>> in = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  int ans = 4;
  EXPECT_EQ(s.longestIncreasingPath(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}