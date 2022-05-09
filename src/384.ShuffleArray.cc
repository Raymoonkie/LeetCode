#include "headers.h"

class Solution {
 public:
  Solution(vector<int>& nums) {
    vals = nums;
    n = nums.size();

    shuffled.resize(n);
  }

  vector<int> reset() { return vals; }

  vector<int> shuffle() {
    for (int i = 0; i < n; i++) {
      shuffled[i] = vals[i];
    }

    int leftVals = n;
    for (int i = n - 1; i >= 0; i--) {
      int j = rand() % leftVals;
      swap(shuffled[i], shuffled[j]);
      leftVals--;
    }

    return shuffled;
  }

 private:
  vector<int> vals;
  vector<int> shuffled;
  int n;
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ShuffleArray, ShuffleArray_1) {
  vector<int> in = {1, 2, 3};
  Solution* s = new Solution(in);

  vector<int> ans1 = {3, 1, 2};
  EXPECT_EQ(s->shuffle(), ans1);

  vector<int> ans2 = {1, 2, 3};
  EXPECT_EQ(s->reset(), ans2);

  vector<int> ans3 = {1, 3, 2};
  EXPECT_EQ(s->shuffle(), ans3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}