#include "headers.h"

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (res.back()[1] < intervals[i][0]) {
        res.push_back(intervals[i]);
      } else {
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      }
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MergeIntervals, MergeIntervals_1) {
  Solution s;
  vector<vector<int>> in = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ans = {{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(s.merge(in), ans);
}

TEST(MergeIntervals, MergeIntervals_2) {
  Solution s;
  vector<vector<int>> in = {{1, 4}, {4, 5}};
  vector<vector<int>> ans = {{1, 5}};
  EXPECT_EQ(s.merge(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}