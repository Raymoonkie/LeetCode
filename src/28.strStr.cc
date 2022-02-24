#include "headers.h"

class Solution {
  int next[50005];

 public:
  int strStr(string s, string p) {
    if (p.length() == 0) {
      return 0;
    }

    buildNext(p);

    return search(s, p);
  }
  void buildNext(string p) {
    int i = 1, now = 0;

    while (i < p.length()) {
      if (p[i] == p[now]) {
        now++;
        next[i] = now;
        i++;
      } else if (now != 0) {
        now = next[now - 1];
      } else {
        i++;
        next[i] = now;
      }
    }
  }

  int search(string s, string p) {
    int tar = 0, pos = 0;
    while (tar < s.length()) {
      if (s[tar] == p[pos]) {
        tar++;
        pos++;
      } else if (pos != 0) {
        pos = next[pos - 1];
      } else {
        tar++;
      }

      if (pos == p.length()) {
        return tar - pos;
      }
    }

    return -1;
  }
};

TEST(strStr, strStr_1) {
  Solution s;
  string s1 = "123";
  string s2 = "";
  int ans = 0;
  EXPECT_EQ(s.strStr(s1, s2), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}