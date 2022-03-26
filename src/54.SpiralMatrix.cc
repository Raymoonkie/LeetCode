#include "headers.h"

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // directions
    vector<vector<int>> ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    vector<int> count = {n, m - 1};

    // direction index
    int di = 0;
    int i = 0, j = -1;
    while (count[di % 2]) {
      for (int x = 0; x < count[di % 2]; x++) {
        i += ds[di][0];
        j += ds[di][1];

        res.push_back(matrix[i][j]);
      }

      count[di % 2]--;
      di = (di + 1) % 4;
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SpiralMatrix, SpiralMatrix_1) {
  Solution s;
  vector<vector<int>> in = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> ans = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(s.spiralOrder(in), ans);
}

TEST(SpiralMatrix, SpiralMatrix_2) {
  Solution s;
  vector<vector<int>> in = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> ans = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  EXPECT_EQ(s.spiralOrder(in), ans);
}

TEST(SpiralMatrix, SpiralMatrix_3) {
  Solution s;
  vector<vector<int>> in = {{3}, {2}};
  vector<int> ans = {3, 2};
  EXPECT_EQ(s.spiralOrder(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}