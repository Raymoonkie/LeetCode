#include "headers.h"

class Solution {
 public:
  string longestPalindrome(string s) {
    return double_pointer_solution(s);
    // return dp_solution(s);
  }

  string double_pointer_solution(string s) {
    if (s.length() == 0) {
      return s;
    }
    int lp = 0;
    int rp = 0;

    int maxStart = 0;
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
      int len1 = expand(s, i, i);
      int len2 = expand(s, i, i + 1);

      int len = max(len1, len2);

      if (len > maxLen) {
        maxStart = i - (len - 1) / 2;
        maxLen = len;
      }
    }

    return s.substr(maxStart, maxLen);
  }

  int expand(string s, int lp, int rp) {
    while (lp >= 0 && rp < s.length() && s[rp] == s[lp]) {
      lp--;
      rp++;
    }
    return rp - lp - 1;
  }

  string dp_solution(string s) {
    if (s.length() == 0) {
      return s;
    }
    int len = s.length();

    // dp[start][end] meanign weather it is a palindorm
    bool dp[len][len];
    memset(dp, false, len * len * sizeof(bool));

    int maxStart = 0;
    int maxLen = 1;
    for (int end = 0; end < len; end++) {
      dp[end][end] = true;
      for (int start = end -1; start >= 0; start--) {
        if (s[start] == s[end]) {
          if (end - start == 1 || dp[start + 1][end - 1]) {
            dp[start][end] = true;
            if (end - start + 1 > maxLen) {
              maxLen = end - start + 1;
              maxStart = start;
            }
          }
        }
      }
    }

    return s.substr(maxStart, maxLen);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LongestPalindromicSubString, LongestPalindromicSubString_1) {
  Solution s;
  string in = "babad";
  string ans = "bab";
  EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(LongestPalindromicSubString, LongestPalindromicSubString_2) {
  Solution s;
  string in = "abbc";
  string ans = "bb";
  EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(LongestPalindromicSubString, LongestPalindromicSubString_3) {
  Solution s;
  string in = "";
  string ans = "";
  EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(LongestPalindromicSubString, LongestPalindromicSubString_4) {
  Solution s;
  string in = "a";
  string ans = "a";
  EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(LongestPalindromicSubString, LongestPalindromicSubString_5) {
  Solution s;
  string in = "ac";
  string ans = "a";
  EXPECT_EQ(s.longestPalindrome(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}