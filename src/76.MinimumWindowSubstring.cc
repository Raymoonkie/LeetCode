#include "headers.h"

class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> map(128, 0);
    for (auto c : t) map[c]++;
    int counter = t.size(), begin = 0, end = 0;
    int len = INT_MAX, len_start = 0;
    while (end < s.size()) {
      if (map[s[end++]]-- > 0) counter--;
      while (counter == 0) {
        if (end - begin < len) len = end - (len_start = begin);
        if (map[s[begin++]]++ == 0) counter++;
      }
    }

    return len == INT_MAX ? "" : s.substr(len_start, len);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MinimumWindowSubstring, MinimumWindowSubstring_1) {
  Solution s;
  EXPECT_EQ(s.minWindow(string("ADOBECODEBANC"), string("ABC")),
            string("BANC"));
  EXPECT_EQ(s.minWindow(string("a"), string("a")), string("a"));
  EXPECT_EQ(s.minWindow(string("a"), string("aa")), string(""));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}