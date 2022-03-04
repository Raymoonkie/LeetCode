#include "headers.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() < 2) {
      return s.length();
    }
    unordered_map<char, int> lastIndex;

    int maxLen = 0;
    for (int i = 0, j = 0; j < s.length(); j++) {
      i = max(i, lastIndex[s[j]]);

      maxLen = max(j - i + 1, maxLen);
      lastIndex[s[j]] = j + 1;
    }

    return maxLen;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_1) {
  Solution s;
  string in = "abcabcbb";
  int ans = 3;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_2) {
  Solution s;
  string in = "bbbb";
  int ans = 1;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_3) {
  Solution s;
  string in = "pwwkew";
  int ans = 3;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_4) {
  Solution s;
  string in = "abcabcde";
  int ans = 5;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_5) {
  Solution s;
  string in = " ";
  int ans = 1;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(LongestSubStringWithoutRepeatingChar,
     LongestSubStringWithoutRepeatingChar_6) {
  Solution s;
  string in = "au";
  int ans = 2;
  EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}