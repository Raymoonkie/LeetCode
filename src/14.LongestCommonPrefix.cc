#include "headers.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1) {
      return strs[0];
    }

    size_t min_len = strs[0].length();
    for (int i = 0; i < strs.size(); i++) {
      min_len = std::min(min_len, strs[i].length());
    }

    if (min_len == 0) {
      return "";
    }

    for (int i = 0; i < strs.size(); i++) {
      min_len = std::min(min_len, lcp(strs[0], strs[i]));
    }

    return strs[0].substr(0, min_len);
  }

  size_t lcp(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        return i;
      }
    }

    return a.length();
  }
};

TEST(LongestCommonPrefix, LongestCommonPrefix_1) {
  Solution s;
  vector<string> in = {"ab", "ab", "ac"};
  string ans = "a";
  EXPECT_EQ(s.longestCommonPrefix(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}