#include "headers.h"

class Solution {
  vector<pair<int, int>> directions = {{1, 1},  {0, 1},   {1, 0},  {0, -1},
                                       {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) { return s1(grid); }

  int s1(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return -1;
    if (grid[0][0] || grid[m - 1][m - 1]) return -1;

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    grid[0][0] = 1;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (cur.first == m - 1 && cur.second == m - 1)
        return grid[cur.first][cur.second];

      for (auto d : directions) {
        int x = cur.first + d.first;
        int y = cur.second + d.second;

        if (x < 0 || x >= m || y < 0 || y >= m || grid[x][y]) continue;
        q.emplace(x, y);
        grid[x][y] = grid[cur.first][cur.second] + 1;
      }
    }

    return -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ShortestPathInBinarymatrix, ShortestPathInBinarymatrix_1) {
  Solution s;
  vector<vector<int>> in = {{0, 1}, {1, 0}};
  int ans = 2;
  EXPECT_EQ(s.shortestPathBinaryMatrix(in), ans);
}

TEST(ShortestPathInBinarymatrix, ShortestPathInBinarymatrix_2) {
  Solution s;
  vector<vector<int>> in = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int ans = 4;
  EXPECT_EQ(s.shortestPathBinaryMatrix(in), ans);
}

TEST(ShortestPathInBinarymatrix, ShortestPathInBinarymatrix_3) {
  Solution s;
  vector<vector<int>> in = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int ans = -1;
  EXPECT_EQ(s.shortestPathBinaryMatrix(in), ans);
}

TEST(ShortestPathInBinarymatrix, ShortestPathInBinarymatrix_4) {
  Solution s;
  vector<vector<int>> in = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
  int ans = -1;
  EXPECT_EQ(s.shortestPathBinaryMatrix(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}