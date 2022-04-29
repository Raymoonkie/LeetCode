#include "headers.h"

class Solution {
 public:
  int rob(vector<int> &nums) { return s3(nums); }

  int s1(vector<int> &nums, int i = 0) {
    return i < nums.size() ? max(s1(nums, i + 1), nums[i] + s1(nums, i + 2)) : 0;
  }

  int s2(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];

    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return max(dp[n - 1], dp[n - 2]);
  }

  int s3(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];

    int n = nums.size();
    int cur = 0;
    int prev_1 = 0;
    int prev_2 = 0;
    for (int i = 0; i < n; i++) {
      cur = max(prev_1, prev_2 + nums[i]);
      prev_2 = prev_1;
      prev_1 = cur;
    }

    return cur;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(HouseRobber, HouseRobber_1) {
  Solution s;
  vector<int> in = {1, 2, 3, 1};
  int ans = 4;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

TEST(HouseRobber, HouseRobber_2) {
  Solution s;
  vector<int> in = {2, 7, 9, 3, 1};
  int ans = 12;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

TEST(HouseRobber, HouseRobber_3) {
  Solution s;
  vector<int> in = {2, 1, 1, 2};
  int ans = 4;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
  EXPECT_EQ(s.s3(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}