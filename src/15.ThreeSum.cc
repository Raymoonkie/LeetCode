#include "headers.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) {
      return res;
    }

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r) {
        int sum = nums[l] + nums[r] + nums[i];
        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          res.push_back(vector<int>{nums[i], nums[l], nums[r]});

          while (l < r && nums[l] == nums[l + 1]) l++;
          while (l < r && nums[r] == nums[r - 1]) r--;
          l++;
          r--;
        }
      }

      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ThreeSum, ThreeSum_1) {
  Solution s;
  vector<int> in = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(in), ans);
}

TEST(ThreeSum, ThreeSum_2) {
  Solution s;
  vector<int> in = {-2, 0, 1, 1, 2};
  vector<vector<int>> ans = {{-2, 0, 2}, {-2, 1, 1}};
  EXPECT_EQ(s.threeSum(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}