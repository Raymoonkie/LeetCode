#include "headers.h"

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX;
    int b = INT_MAX;
    for (auto num : nums) {
      if (num <= a) {
        a = num;
      } else if (num <= b) {
        b = num;
      } else {
        return true;
      }
    }

    return false;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(IncreasingTripletSubsequence, IncreasingTripletSubsequence_1) {
  Solution s;
  vector<int> in = {1, 2, 3, 4, 5};
  EXPECT_EQ(s.increasingTriplet(in), true);
}

TEST(IncreasingTripletSubsequence, IncreasingTripletSubsequence_2) {
  Solution s;
  vector<int> in = {5, 4, 3, 2, 1};
  EXPECT_EQ(s.increasingTriplet(in), false);
}

TEST(IncreasingTripletSubsequence, IncreasingTripletSubsequence_3) {
  Solution s;
  vector<int> in = {2, 1, 5, 0, 4, 6};
  EXPECT_EQ(s.increasingTriplet(in), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}