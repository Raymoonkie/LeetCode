#include "headers.h"

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrace(res, 0, nums);
    return res;
  }

  void backtrace(vector<vector<int>>& ans, int begin, vector<int>& nums) {
    if (begin >= nums.size()) {
      ans.push_back(nums);
    } else {
      for (int i = begin; i < nums.size(); i++) {
        swap(nums[begin], nums[i]);
        backtrace(ans, begin + 1, nums);
        swap(nums[begin], nums[i]);
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(Permutations, Permutations_1) {
  Solution s;
  vector<int> in = {1, 2, 3};
  vector<vector<int>> ans = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                             {2, 3, 1}, {3, 2, 1}, {3, 1, 2}};
  EXPECT_EQ(s.permute(in), ans);
}

TEST(Permutations, Permutations_2) {
  Solution s;
  vector<int> in = {1, 2};
  vector<vector<int>> ans = {{1, 2}, {2, 1}};
  EXPECT_EQ(s.permute(in), ans);
}

TEST(Permutations, Permutations_3) {
  Solution s;
  vector<int> in = {1};
  vector<vector<int>> ans = {{1}};
  EXPECT_EQ(s.permute(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}