#include "headers.h"

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    dfs(nums, 0, sub, subs);

    return subs;

    // return iterative(nums);
  }

  void dfs(vector<int>& nums, int begin, vector<int>& sub,
           vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int i = begin; i < nums.size(); i++) {
      sub.push_back(nums[i]);
      dfs(nums, i + 1, sub, subs);
      sub.pop_back();
    }
  }

  vector<vector<int>> iterative(vector<int>& nums) {
    vector<vector<int>> res = {{}};

    for (int num : nums) {
      int n = res.size();
      for (int i = 0; i < n; i++) {
        res.push_back(res[i]);
        res.back().push_back(num);
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

TEST(Subsets, Subsets_1) {
  Solution s;
  vector<int> in = {1, 2, 3};
  vector<vector<int>> ans = {{},     {1}, {1, 2}, {1, 2, 3},
                             {1, 3}, {2}, {2, 3}, {3}};
  EXPECT_EQ(s.subsets(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}