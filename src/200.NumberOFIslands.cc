#include "headers.h"

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j, m, n);
          count++;
        }
      }
    }

    return count;
  }

  void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
    grid[i][j] = 0;
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i, j + 1, m, n);
    dfs(grid, i, j - 1, m, n);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(NumberOFIslands, NumberOFIslands_1) {
  Solution s;
  vector<vector<char>> in = {{'1', '1', '1', '1', '0'},
                             {'1', '1', '0', '1', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'}};
  int ans = 1;
  EXPECT_EQ(s.numIslands(in), ans);
}

TEST(NumberOFIslands, NumberOFIslands_2) {
  Solution s;
  vector<vector<char>> in = {{'1', '1', '0', '0', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'0', '0', '0', '1', '1'}};
  int ans = 3;
  EXPECT_EQ(s.numIslands(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}