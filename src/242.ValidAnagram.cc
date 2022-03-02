#include "headers.h"

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    int ans[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      ans[s[i] - 'a']++;
      ans[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (ans[i]) {
        return false;
      }
    }

    return true;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ValidAnagram, ValidAnagram_1) {
  Solution s;
  string a = "rat";
  string t = "car";
  bool ans = false;
  EXPECT_EQ(s.isAnagram(a, t), ans);
}

TEST(ValidAnagram, ValidAnagram_2) {
  Solution s;
  string a = "anagram";
  string t = "nagaram";
  bool ans = true;
  EXPECT_EQ(s.isAnagram(a, t), ans);
}

TEST(ValidAnagram, ValidAnagram_3) {
  Solution s;
  string a = "aa";
  string t = "vv";
  bool ans = false;
  EXPECT_EQ(s.isAnagram(a, t), ans);
}

TEST(ValidAnagram, ValidAnagram_4) {
  Solution s;
  string a = "nl";
  string t = "cx";
  bool ans = false;
  EXPECT_EQ(s.isAnagram(a, t), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}