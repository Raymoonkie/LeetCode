#include "headers.h"

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int ans = (len +1) * len / 2;
    for (int i = 0; i < len; i++) {
      ans -= nums[i];
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MissingNumber, MissingNumber_1) {
  Solution s;
  vector<int> in = {3,0,1};
  int ans = 2;
  EXPECT_EQ(s.missingNumber(in), ans);
}

TEST(MissingNumber, MissingNumber_2) {
  Solution s;
  vector<int> in = {0,1};
  int ans = 2;
  EXPECT_EQ(s.missingNumber(in), ans);
}

TEST(MissingNumber, MissingNumber_3) {
  Solution s;
  vector<int> in = {9,6,4,2,3,5,7,0,1};
  int ans = 8;
  EXPECT_EQ(s.missingNumber(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}