#include "headers.h"

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) {
        return 1;
    }

    int l_pos = 0;
    int r_pos = 1;

    while (r_pos < nums.size())
    {
        if (nums[l_pos] != nums[r_pos]) {
            l_pos ++;
            nums[l_pos] = nums[r_pos];
        }
        r_pos ++;
    }

    return l_pos + 1;
  }
};

TEST(RemoveDuplicatesFromSortedArray, RemoveDuplicatesFromSortedArray_1) {
  Solution s;
  vector<int> in1 = {0,0,1,1,1,2,2,3,3,4};
  int ans1 = 5;
  EXPECT_EQ(s.removeDuplicates(in1), ans1);

  vector<int> in2 = {1};
  int ans2 = 1;
  EXPECT_EQ(s.removeDuplicates(in2), ans2);

  vector<int> in3 = {1,2,3};
  int ans3 = 3;
  EXPECT_EQ(s.removeDuplicates(in3), ans3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}