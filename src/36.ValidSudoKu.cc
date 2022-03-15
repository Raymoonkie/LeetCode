#include "headers.h"

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<short> row(9, 0);
    vector<short> col(9, 0);
    vector<short> sub_block(9, 0);

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int idx = 1 << (board[i][j] - '0');
          int k = i / 3 * 3 + j / 3;
          if (row[i] & idx | col[j] & idx | sub_block[k] & idx) {
            return false;
          }

          row[i] |= idx;
          col[j] |= idx;
          sub_block[k] |= idx;
        }
      }
    }

    return true;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ValidSudoKu, ValidSudoKu_1) {
  Solution s;
  vector<vector<char>> in = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  bool ans = true;
  EXPECT_EQ(s.isValidSudoku(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}