#include "headers.h"

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') {
        dfs(board, i, 0, m, n);
      }

      if (board[i][n - 1] == 'O') {
        dfs(board, i, n - 1, m, n);
      }
    }

    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O') {
        dfs(board, 0, j, m, n);
      }

      if (board[m - 1][j] == 'O') {
        dfs(board, m - 1, j, m, n);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }

        if (board[i][j] == '#') {
          board[i][j] = 'O';
        }
      }
    }
  }

  void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
    board[i][j] = '#';
    dfs(board, i, j - 1, m, n);
    dfs(board, i, j + 1, m, n);
    dfs(board, i - 1, j, m, n);
    dfs(board, i + 1, j, m, n);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SurroundedRegions, SurroundedRegions_1) {
  Solution s;
  vector<vector<char>> in = {{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};

  vector<vector<char>> ans = {{'X', 'X', 'X', 'X'},
                              {'X', 'X', 'X', 'X'},
                              {'X', 'X', 'X', 'X'},
                              {'X', 'O', 'X', 'X'}};
  s.solve(in);
  EXPECT_EQ(in, ans);
}

TEST(SurroundedRegions, SurroundedRegions_2) {
  Solution s;
  vector<vector<char>> in = {{'X'}};

  vector<vector<char>> ans = {{'X'}};
  s.solve(in);
  EXPECT_EQ(in, ans);
}

TEST(SurroundedRegions, SurroundedRegions_3) {
  Solution s;
  vector<vector<char>> in = {{'O'}};

  vector<vector<char>> ans = {{'O'}};
  s.solve(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}