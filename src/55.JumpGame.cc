#include "headers.h"

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    return greedy(nums);
    // return dp(nums);
  }

  bool greedy(vector<int>& nums) {
    int farest = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (farest < i) {
        return false;
      }

      farest = max(i + nums[i], farest);
      if (farest > nums.size() - 1) {
        return true;
      }
    }

    return true;
  }

  bool dp(vector<int>& nums) {
    int n = nums.size();
    vector<bool> backup(n, false);
    backup[0] = true;

    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (backup[j] && nums[j] + j >= i) {
          backup[i] = true;
          break;
        }
      }
    }

    return backup[n - 1];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(JumpGame, JumpGame_1) {
  Solution s;
  vector<int> in = {2, 3, 1, 1, 4};
  bool ans = true;
  EXPECT_EQ(s.canJump(in), ans);
}

TEST(JumpGame, JumpGame_2) {
  Solution s;
  vector<int> in = {3, 2, 1, 0, 4};
  bool ans = false;
  EXPECT_EQ(s.canJump(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}