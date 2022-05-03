#include "headers.h"

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int alive = neighbor(board, i - 1, j - 1) + neighbor(board, i - 1, j) +
                    neighbor(board, i - 1, j + 1) + neighbor(board, i, j - 1) +
                    neighbor(board, i, j + 1) + neighbor(board, i + 1, j - 1) +
                    neighbor(board, i + 1, j) + neighbor(board, i + 1, j + 1);

        if (board[i][j]) {
          if (alive < 2 || alive > 3) {
            board[i][j] = 1;
          } else {
            board[i][j] = 3;
          }
        } else {
          if (alive == 3) {
            board[i][j] = 2;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] >>= 1;
      }
    }
  }

  int neighbor(vector<vector<int>>& board, int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return 0;

    return board[x][y] & 1 ? 1 : 0;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(GameOfLife, GameOfLife_1) {
  Solution s;
  vector<vector<int>> in = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  vector<vector<int>> ans = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
  s.gameOfLife(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}