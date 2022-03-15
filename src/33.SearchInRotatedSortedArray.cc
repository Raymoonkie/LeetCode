#include "headers.h"

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] >= nums[0]) {
        if (target >= nums[0] && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[nums.size() - 1]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }

    return -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SearchInRotatedSortedArray, SearchInRotatedSortedArray_1) {
  Solution s;
  vector<int> in = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  int ans = 4;
  EXPECT_EQ(s.search(in, target), ans);
}

TEST(SearchInRotatedSortedArray, SearchInRotatedSortedArray_2) {
  Solution s;
  vector<int> in = {3, 1};
  int target = 3;
  int ans = 0;
  EXPECT_EQ(s.search(in, target), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}