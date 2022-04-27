#include "headers.h"

class Solution {
 public:
  int findPeakElement(vector<int>& nums) { return s1(nums); }

  int s1(vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 1) return 0;
    if (nums[1] < nums[0]) return 0;
    if (nums[n - 2] < nums[n - 1]) return n - 1;
    for (int i = 1; i < n - 1; i++) {
      if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        return i;
      }
    }

    return -1;
  }

  int s2(vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 1) return 0;
    if (nums[1] < nums[0]) return 0;
    if (nums[n - 2] < nums[n - 1]) return n - 1;

    int low = 1;
    int high = n - 2;
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
      else if (nums[mid] < nums[mid - 1]) high = mid - 1;
      else if (nums[mid] < nums[mid + 1]) low = mid + 1;
    }

    return -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FindPeakElement, FindPeakElement_1) {
  Solution s;
  vector<int> in = {1, 2, 3, 1};
  int ans = 2;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

TEST(FindPeakElement, FindPeakElement_2) {
  Solution s;
  vector<int> in = {1, 2, 1, 3, 5, 6, 4};
  EXPECT_EQ(s.s1(in), 1);
  EXPECT_EQ(s.s2(in), 5);
}

TEST(FindPeakElement, FindPeakElement_3) {
  Solution s;
  vector<int> in = {1, 2, 1, 2,1};
  EXPECT_EQ(s.s1(in), 1);
  EXPECT_EQ(s.s2(in), 1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}