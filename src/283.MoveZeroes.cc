#include "headers.h"

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[j++] = nums[i];
      }
    }

    while (j < nums.size()) {
      nums[j++] = 0;
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MoveZeroes, MoveZeroes_1) {
  Solution s;
  vector<int> in = {0, 1, 0, 3, 12};
  vector<int> ans = {1, 3, 12, 0, 0};

  s.moveZeroes(in);
  EXPECT_EQ(in, ans);
}

TEST(MoveZeroes, MoveZeroes_2) {
  Solution s;
  vector<int> in = {0};
  vector<int> ans = {0};

  s.moveZeroes(in);
  EXPECT_EQ(in, ans);
}

TEST(MoveZeroes, MoveZeroes_3) {
  Solution s;
  vector<int> in = {1};
  vector<int> ans = {1};

  s.moveZeroes(in);
  EXPECT_EQ(in, ans);
}

TEST(MoveZeroes, MoveZeroes_4) {
  Solution s;
  vector<int> in = {0, 1};
  vector<int> ans = {1, 0};

  s.moveZeroes(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}