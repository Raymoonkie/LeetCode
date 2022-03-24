#include "headers.h"

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    backtrace(ans, 0, nums);
    return ans;
  }

  void backtrace(vector<vector<int>>& res, int begin, vector<int> nums) {
    if (begin == nums.size() - 1) {
      res.push_back(nums);
    } else {
      for (int i = begin; i < nums.size(); i++) {
        if (i != begin && (nums[i] == nums[begin] || nums[i] == nums[i - 1]))
          continue;
        swap(nums[begin], nums[i]);
        backtrace(res, begin + 1, nums);
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(Permutations_2, Permutations_2_1) {
  Solution s;
  vector<int> in = {1, 1, 2};
  vector<vector<int>> ans = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
  EXPECT_EQ(s.permuteUnique(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}