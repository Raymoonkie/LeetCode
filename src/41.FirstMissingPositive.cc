#include "headers.h"

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return n + 1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FirstMissingPositive, FirstMissingPositive_1) {
  Solution s;
  vector<int> in = {1, 2, 0};
  int ans = 3;
  EXPECT_EQ(s.firstMissingPositive(in), ans);
}

TEST(FirstMissingPositive, FirstMissingPositive_2) {
  Solution s;
  vector<int> in = {INT_MAX};
  int ans = 1;
  EXPECT_EQ(s.firstMissingPositive(in), ans);
}

TEST(FirstMissingPositive, FirstMissingPositive_3) {
  Solution s;
  vector<int> in = {3, 4, -1, 1};
  int ans = 2;
  EXPECT_EQ(s.firstMissingPositive(in), ans);
}

TEST(FirstMissingPositive, FirstMissingPositive_4) {
  Solution s;
  vector<int> in = {7, 8, 9, 11, 12};
  int ans = 1;
  EXPECT_EQ(s.firstMissingPositive(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}