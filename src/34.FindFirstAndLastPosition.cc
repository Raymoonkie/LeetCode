#include "headers.h"

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }

    int l = 0;
    int r = nums.size() - 1;

    int tmp = -1;

    while (l < r) {
      int mid = (l + r) / 2;

      if (nums[l] == target) {
        break;
      }

      if (nums[mid] < target) {
        l = mid + 1;
      } else if (nums[mid] == target) {
        r = mid;
      } else {
        r = mid - 1;
      }
    }

    if (nums[l] != target) return {-1, -1};
    tmp = l;

    r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2 + 1;

      if (nums[r] == target) {
        break;
      }

      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] == target) {
        l = mid;
      } else {
        l = mid - 1;
      }
    }

    return {tmp, r};
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_1) {
  Solution s;
  vector<int> in = {5, 7, 7, 8, 8, 10};
  vector<int> ans = {3, 4};
  EXPECT_EQ(s.searchRange(in, 8), ans);
}

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_2) {
  Solution s;
  vector<int> in = {5, 7, 7, 8, 8, 10};
  vector<int> ans = {-1, -1};
  EXPECT_EQ(s.searchRange(in, 6), ans);
}

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_3) {
  Solution s;
  vector<int> in = {};
  vector<int> ans = {-1, -1};
  EXPECT_EQ(s.searchRange(in, 6), ans);
}

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_4) {
  Solution s;
  vector<int> in = {1};
  vector<int> ans = {0, 0};
  EXPECT_EQ(s.searchRange(in, 1), ans);
}

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_5) {
  Solution s;
  vector<int> in = {1, 1};
  vector<int> ans = {0, 1};
  EXPECT_EQ(s.searchRange(in, 1), ans);
}

TEST(FindFirstAndLastPosition, FindFirstAndLastPosition_6) {
  Solution s;
  vector<int> in = {1, 2};
  vector<int> ans = {0, 0};
  EXPECT_EQ(s.searchRange(in, 1), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}