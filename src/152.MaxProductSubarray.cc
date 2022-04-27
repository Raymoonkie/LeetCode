#include "headers.h"

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int max_dp = nums[0];
    int min_dp = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) {
        swap(max_dp, min_dp);
      }

      max_dp = max(nums[i], nums[i] * max_dp);
      min_dp = min(nums[i], nums[i] * min_dp);
      result = max(result, max_dp);
    }

    return result;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MaxProductSubarray, MaxProductSubarray_1) {
  Solution s;
  vector<int> in = {2, 3, -2, 4};
  int ans = 6;
  EXPECT_EQ(s.maxProduct(in), ans);
}

TEST(MaxProductSubarray, MaxProductSubarray_2) {
  Solution s;
  vector<int> in = {-2, 0, -1};
  int ans = 0;
  EXPECT_EQ(s.maxProduct(in), ans);
}

TEST(MaxProductSubarray, MaxProductSubarray_3) {
  Solution s;
  vector<int> in = {-2};
  int ans = -2;
  EXPECT_EQ(s.maxProduct(in), ans);
}

TEST(MaxProductSubarray, MaxProductSubarray_4) {
  Solution s;
  vector<int> in = {-2, 3, -4};
  int ans = 24;
  EXPECT_EQ(s.maxProduct(in), ans);
}

TEST(MaxProductSubarray, MaxProductSubarray_5) {
  Solution s;
  vector<int> in = {-2, -3, -4};
  int ans = 12;
  EXPECT_EQ(s.maxProduct(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}