#include "headers.h"

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int len = height.size();
    int l = 0;
    int r = len - 1;

    int max_area = 0;
    while (l < r) {
      max_area = max(max_area, min(height[l], height[r]) * (r - l));

      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return max_area;
  }
};
static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ContainerWithMostWater, ContainerWithMostWater_1) {
  Solution s;
  vector<int> in = {1, 8, 6, 4, 5, 2, 8, 3, 7};
  int ans = 49;
  EXPECT_EQ(s.maxArea(in), ans);
}

TEST(ContainerWithMostWater, ContainerWithMostWater_2) {
  Solution s;
  vector<int> in = {1, 2, 1};
  int ans = 2;
  EXPECT_EQ(s.maxArea(in), ans);
}

TEST(ContainerWithMostWater, ContainerWithMostWater_3) {
  Solution s;
  vector<int> in = {1, 1};
  int ans = 1;
  EXPECT_EQ(s.maxArea(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}