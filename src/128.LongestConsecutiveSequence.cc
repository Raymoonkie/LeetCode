#include "headers.h"

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) { return s3(nums); }

  int s1(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    int longest = 0;
    for (int num : nums) {
      int curLongest = 1;
      for (int j = 1; s.count(num - j); j++) s.erase(num - j), curLongest++;
      for (int j = 1; s.count(num + j); j++) s.erase(num - j), curLongest++;

      longest = max(longest, curLongest);
    }

    return longest;
  }

  int s2(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    int longest = 0;
    for (int num : nums) {
      // shortcut, reduce dupilicate compute
      if (s.count(num - 1)) continue;

      int j = 1;
      while (s.count(num + j)) j++;

      longest = max(longest, j);
    }

    return longest;
  }

  int s3(vector<int>& nums) {
    unordered_map<int, int> m;
    int r = 0;

    for (int i : nums) {
      if (m[i]) continue;
      r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] =
                     m[i + 1] + m[i - 1] + 1);
    }

    return r;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestConsecutiveSequence, LongestConsecutiveSequence_1) {
  Solution s;
  vector<int> in = {100, 4, 200, 1, 3, 2};
  int ans = 4;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
  EXPECT_EQ(s.s3(in), ans);
}

TEST(LongestConsecutiveSequence, LongestConsecutiveSequence_2) {
  Solution s;
  vector<int> in = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int ans = 9;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
  EXPECT_EQ(s.s3(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}