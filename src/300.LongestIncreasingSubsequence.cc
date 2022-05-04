#include "headers.h"

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) { return s2(nums); }

  int s1(vector<int>& nums, int i, int prev_i) {
    if (i >= nums.size()) return 0;

    int take = 0;
    if (prev_i == -1 || nums[i] > nums[prev_i]) {
      take = 1 + s1(nums, i + 1, i);
    }
    int not_take = s1(nums, i + 1, prev_i);

    return max(take, not_take);
  }

  int s2(vector<int>& nums) {
    vector<vector<int>> dp;
    dp.resize(nums.size(), vector<int>(1 + nums.size(), -1));
    return solve2(nums, 0, -1, dp);
  }

  int solve2(vector<int>& nums, int i, int prev_i, vector<vector<int>>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[i][prev_i + 1] != -1) {
      return dp[i][prev_i + 1];
    }

    int take = 0;
    if (prev_i == -1 || nums[i] > nums[prev_i]) {
      take = 1 + solve2(nums, i + 1, i, dp);
    }
    int not_take = solve2(nums, i + 1, prev_i, dp);

    dp[i][prev_i + 1] = max(take, not_take);

    return dp[i][prev_i + 1];
  }

  int s3(vector<int>& nums) {
    vector<int> dp;
    dp.resize(size(nums) + 1, -1);
    return solve3(nums, 0, -1, dp);
  }

  int solve3(vector<int>& nums, int i, int prev_i, vector<int>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[prev_i + 1] != -1) {
      return dp[prev_i + 1];
    }

    int take = 0;
    if (prev_i == -1 || nums[i] > nums[prev_i]) {
      take = 1 + solve3(nums, i + 1, i, dp);
    }
    int not_take = solve3(nums, i + 1, prev_i, dp);

    dp[prev_i + 1] = max(take, not_take);

    return dp[prev_i + 1];
  }

  int s4(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
          ans = max(ans, dp[i]);
        }
      }
    }

    return ans;
  }

  int s5(vector<int>& nums) {
    int len = 0;

    for (auto num : nums) {
      if (0 == len || nums[len - 1] < num) {
        nums[len] = num;
        len += 1;
      } else {
        *lower_bound(nums.begin(), nums.begin() + len, num) = num;
      }
    }

    return len;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestIncreasingSubsequence, LongestIncreasingSubsequence_1) {
  Solution s;
  vector<int> in = {10, 9, 2, 5, 3, 7, 101, 18};
  int ans = 4;
  EXPECT_EQ(s.s1(in, 0, -1), ans);
  EXPECT_EQ(s.s2(in), ans);
  EXPECT_EQ(s.s3(in), ans);
  EXPECT_EQ(s.s4(in), ans);
  EXPECT_EQ(s.s5(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}