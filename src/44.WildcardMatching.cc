#include "headers.h"

class Solution {
 public:
  bool isMatch(string s, string p) { return s1(s.c_str(), p.c_str()); }

  bool s1(const char* s, const char* p) {
    const char* star = nullptr;
    const char* last_match = s;
    while (*s) {
      if (*p == '?' || *p == *s) {
        p++;
        s++;
      } else if (*p == '*') {
        // make checkpoint for backtrace
        star = p++;
        last_match = s;
      } else if (star) {
        // backtrace
        p = star + 1;
        last_match++;
        s = last_match;
      } else {
        return false;
      }
    }
    // s reach end
    while (*p == '*') p++;

    return !*p;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WildcardMatching, WildcardMatching_1) {
  Solution s;
  EXPECT_EQ(s.isMatch(string("aa"), string("a")), false);
  EXPECT_EQ(s.isMatch(string("aa"), string("*")), true);
  EXPECT_EQ(s.isMatch(string("cd"), string("?a")), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}