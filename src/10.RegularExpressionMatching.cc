#include "headers.h"

class Solution {
 public:
  bool isMatch(string s, string p) {
    // return s2(s.c_str(), p.c_str());
    return s3(s, p);
  }

  bool s1(const char* s, const char* p) {
    if (!*p) {
      return !*s;
    }

    if (p[1] == '*') {
      return (*p == '.' && *s || *s == *p) && isMatch(s + 1, p) || s1(s, p + 2);
    }

    if (*p == '.') {
      return *s && isMatch(s + 1, p + 1);
    }

    return *s == *p && isMatch(s + 1, p + 1);
  }

  bool s2(const char* s, const char* p) {
    for (char c = *p; c; ++s, c = *p) {
      if (*(p + 1) != '*')
        p++;
      else if (s2(s, p + 2))
        return true;

      if (!*s || (c != '.') && c != *s) return false;
    }

    return !*s;
  }

  bool s3(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] =
              dp[i][j - 2] ||
              (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        } else {
          dp[i][j] = i && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }

    return dp[m][n];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(RegularExpressionMatching, RegularExpressionMatching_1) {
  Solution s;
  EXPECT_EQ(s.isMatch("aa", "a"), false);
  EXPECT_EQ(s.isMatch("aa", "a*"), true);
  EXPECT_EQ(s.isMatch("ab", ".*"), true);
  EXPECT_EQ(s.isMatch("ab", "a*b"), true);
  EXPECT_EQ(s.isMatch("abb", "a*b"), false);
  EXPECT_EQ(s.isMatch("aab", "c*a*b"), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}