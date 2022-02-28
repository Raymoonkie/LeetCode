#include "headers.h"

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int m = nums[0];
    int c = 1;
    for (int i = 1; i < nums.size(); i ++) {
      if (c == 0) {
        m = nums[i];
      }
      nums[i] == m ? c++ : c--;

    }

    return m;
    // return majority(nums, 0, nums.size() - 1);
  }

  int majority(vector<int>& nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }
    int mid = (left + right) / 2;

    int lm = majority(nums, left, mid);
    int rm = majority(nums, mid + 1, right);

    if (lm == rm) {
      return lm;
    }

    int lmc = 0, rmc = 0;
    for (int i = left; i <= right; i++) {
      if (nums[i] == lm) {
        lmc++;
      }

      if (nums[i] == rm) {
        rmc++;
      }
    }

    return lmc > rmc ? lm : rm;
  }
};

TEST(MajorityElement, MajorityElement_1) {
  Solution s;
  vector<int> in = {3, 2, 3};
  int ans = 3;
  EXPECT_EQ(s.majorityElement(in), ans);
}

TEST(MajorityElement, MajorityElement_2) {
  Solution s;
  vector<int> in = {2,2,1,1,1,2,2};
  int ans = 2;
  EXPECT_EQ(s.majorityElement(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}