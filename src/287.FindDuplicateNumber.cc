#include "headers.h"

class Solution {
 public:
  int findDuplicate(vector<int>& nums) { return s1(nums); }

  int s1(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      nums[index] *= -1;
      if (nums[index] > 0) return abs(nums[i]);
    }
    return -1;
  }

  int s2(vector<int>& nums) {
    int n = nums.size() - 1;
    int low = 1;
    int high = n;
    int mid = -1;
    while (low < high) {
      int mid = low + (high - low) / 2;

      int count = 0;
      for (auto num : nums) {
        if (num <= mid) ++count;
      }

      if (count > mid)
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }

  int s3(vector<int>& nums) {
    int fast = nums[0];
    int slow = nums[0];

    do {
      fast = nums[nums[fast]];
      slow = nums[slow];
    } while (fast != slow);

    slow = nums[0];
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }

    return fast;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FindDuplicateNumber, FindDuplicateNumber_1) {
  Solution s;
  vector<int> in = {1, 3, 4, 2, 2};
  int ans = 2;
  EXPECT_EQ(s.s1(in), ans);

  vector<int> in2 = {1, 3, 4, 2, 2};
  int ans2 = 2;
  EXPECT_EQ(s.s2(in2), ans2);

  vector<int> in3 = {1, 3, 4, 2, 2};
  int ans3 = 2;
  EXPECT_EQ(s.s2(in3), ans3);
}

TEST(FindDuplicateNumber, FindDuplicateNumber_2) {
  Solution s;
  vector<int> in = {2, 2, 2, 2, 2};
  int ans = 2;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}