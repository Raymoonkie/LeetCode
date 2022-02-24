#include "headers.h"

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }


    int last = nums[0];

    int max = last;
    for (int i = 1; i < nums.size(); i++) {
      last > 0 ? last += nums[i] : last = nums[i];

      if (last > max) {
        max = last;
      }
    }

    return max;
  }
};

TEST(MaxSubarray, MaxSubarray_1) {
  Solution s;
  vector<int> in = {5, 4, -1, 7, 8};
  int ans = 23;
  EXPECT_EQ(s.maxSubArray(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}