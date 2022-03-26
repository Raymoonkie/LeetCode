#include "headers.h"

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        int x = i, y = j, last = -5000;
        while (matrix[x][y] != -5000) {
          swap(last, matrix[x][y]);

          swap(x, y);
          y = n - y - 1;
        }
        matrix[x][y] = last;
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(RotateImage, RotateImage_1) {
  Solution s;
  vector<vector<int>> in = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> ans = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  s.rotate(in);
  EXPECT_EQ(in, ans);
}

TEST(RotateImage, RotateImage_2) {
  Solution s;
  vector<vector<int>> in = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  vector<vector<int>> ans = {
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

  s.rotate(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}