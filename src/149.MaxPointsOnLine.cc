#include "headers.h"

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
      unordered_map<pair<int, int>, int, pair_hash> m;
      for (int j = i + 1; j < points.size(); j++) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];
        int g = gcd(dx, dy);
        m[{dx / g, dy / g}]++;

        for (auto p : m) {
          ans = max(ans, p.second);
        }
      }
    }

    return ans + 1;
  }

 private:
  int gcd(int a, int b) {
    while (b) {
      a = a % b;
      swap(a, b);
    }

    return a;
  }

  struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
      return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
  };
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MaxPointsOnLine, MaxPointsOnLine_1) {
  Solution s;
  vector<vector<int>> in = {{1, 1}, {2, 2}, {3, 3}};
  int ans = 3;
  EXPECT_EQ(s.maxPoints(in), ans);
}

TEST(MaxPointsOnLine, MaxPointsOnLine_2) {
  Solution s;
  vector<vector<int>> in = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  int ans = 4;
  EXPECT_EQ(s.maxPoints(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}