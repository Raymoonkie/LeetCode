#include "headers.h"

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;

    vector<pair<int, int>> walls;
    for (auto b : buildings) {
      walls.emplace_back(b[0], -b[2]);
      walls.emplace_back(b[1], b[2]);
    }

    sort(walls.begin(), walls.end());

    multiset<int> left_wall_heights = {0};
    int top = 0;
    for (auto wall : walls) {
      if (wall.second < 0) {
        left_wall_heights.insert(-wall.second);
      } else {
        left_wall_heights.erase(left_wall_heights.find(wall.second));
      }

      if (top != *left_wall_heights.rbegin()) {
        ans.push_back({wall.first, top = *left_wall_heights.rbegin()});
      }
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SkyLineProblem, SkyLineProblem_1) {
  Solution s;
  vector<vector<int>> in = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  vector<vector<int>> ans = {{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}};
  EXPECT_EQ(s.getSkyline(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}