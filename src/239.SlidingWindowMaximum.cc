#include "headers.h"

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> queue;
    vector<int> ans;
    for (int left = 0; left < nums.size(); left++) {
      if (!queue.empty() && queue.front() == left - k) queue.pop_front();

      while (!queue.empty() && nums[queue.back()] < nums[left])
        queue.pop_back();

      queue.push_back(left);

      if (left >= k - 1) ans.push_back(nums[queue.front()]);
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SlidingWindowMaximum, SlidingWindowMaximum_1) {
  Solution s;
  vector<int> in = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> ans = {3, 3, 5, 5, 6, 7};
  EXPECT_EQ(s.maxSlidingWindow(in, 3), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}