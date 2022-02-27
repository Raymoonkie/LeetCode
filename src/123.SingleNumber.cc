#include "headers.h"

class Solution {
 public:
  int bitset[60000];

  int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    for (int i = 0; i < 60000; i++) {
      bitset[i] = 0;
    }

    for (int i = 0; i < nums.size(); i++) {
      bitset[nums[i] + 30000] += 1;
    }

    for (int i = 0; i < 60000; i++) {
      if (bitset[i] == 1) {
        return i - 30000;
      }
    }

    return -1;
  }
};

TEST(SingleNumber, SingleNumber_1) {
  Solution s;
  vector<int> in = {-2222, -2222, -100};
  int ans = -100;
  EXPECT_EQ(s.singleNumber(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}