#include "headers.h"

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, i, j, word, 0)) return true;
      }
    }

    return false;
  }

  bool dfs(vector<vector<char>>& board, int x, int y, string& word, int index) {
    if (index == word.length()) return true;
    if (x < 0 || y < 0 || x == board.size() || y == board[0].size() || board[x][y] != word[index])
      return false;

    board[x][y] = '%';

    bool result = dfs(board, x + 1, y, word, index + 1) ||
                  dfs(board, x - 1, y, word, index + 1) ||
                  dfs(board, x, y + 1, word, index + 1) ||
                  dfs(board, x, y - 1, word, index + 1);
    board[x][y] = word[index];
    return result;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WordSearch, WordSearch_1) {
  Solution s;
  vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word = "ABCCED";
  EXPECT_EQ(s.exist(board, word), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}