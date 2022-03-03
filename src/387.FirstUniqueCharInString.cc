#include "headers.h"

class Solution {
 public:
  int firstUniqChar(string s) {
    if (s.length() == 1) {
      return 0;
    }

    int bitset[26] = {0};

    for (int i = 0; i < s.length(); i++) {
      bitset[s[i] - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (bitset[s[i] - 'a'] == 1) {
        return i;
      }
    }

    return -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FirstUniqueCharInString, FirstUniqueCharInString_1) {
  Solution s;
  string in = "leetcode";
  int ans = 0;
  EXPECT_EQ(s.firstUniqChar(in), ans);
}

TEST(FirstUniqueCharInString, FirstUniqueCharInString_2) {
  Solution s;
  string in = "loveleetcode";
  int ans = 2;
  EXPECT_EQ(s.firstUniqChar(in), ans);
}

TEST(FirstUniqueCharInString, FirstUniqueCharInString_3) {
  Solution s;
  string in = "aabb";
  int ans = -1;
  EXPECT_EQ(s.firstUniqChar(in), ans);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}