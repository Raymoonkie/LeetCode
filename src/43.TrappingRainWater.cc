#include "headers.h"

class Solution {
 public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1, min_height = 0, sum = 0;
    while (l < r) {
      while (l < r && height[l] <= min_height) {
        sum += min_height - height[l++];
      }

      while (l < r && height[r] <= min_height) {
        sum += min_height - height[r--];
      }

      min_height = min(height[l], height[r]);
    }

    return sum;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(TrappingRainWater, TrappingRainWater_1) {
  Solution s;
  vector<int> in = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int ans = 6;
  EXPECT_EQ(s.trap(in), ans);
}

TEST(TrappingRainWater, TrappingRainWater_2) {
  Solution s;
  vector<int> in = {4, 2, 0, 3, 2, 5};
  int ans = 9;
  EXPECT_EQ(s.trap(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}