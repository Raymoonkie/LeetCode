#include "headers.h"

class Solution {
 public:
  int longestSubstring(string s, int k) {
    return s1(s, k, 0, s.size());
  }

  int s1(const string& s, int k, int first, int last) {
    int f[26] = {0};
    for (int j = first; j < last; ++j) ++f[s[j] - 'a'];

    int max_len = 0;
    for (int j = first; j < last;) {
      while (j < last && f[s[j] - 'a'] < k) ++j;
      if (j == last) break;
      int l = j;
      while (l < last && f[s[l] - 'a'] >= k) ++l;
      if (j == first && l == last) return last - first;
      max_len = max(max_len, s1(s, k, j, l));
      j = l;
    }
    return max_len;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestSubstring, LongestSubstring_1) {
  Solution s;
  EXPECT_EQ(s.longestSubstring("aaabb", 3), 3);
  EXPECT_EQ(s.longestSubstring("ababbc", 2), 5);
  EXPECT_EQ(s.longestSubstring("aaabbb", 3), 6);
  EXPECT_EQ(s.longestSubstring("ababacb", 3), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}