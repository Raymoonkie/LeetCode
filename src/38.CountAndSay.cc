#include "headers.h"

class Solution {
 public:
  string countAndSay(int n) {
    string res = "1";

    while (--n) {
      int len = res.length();

      int i = 0;
      string cur = "";
      while (i < len) {
        int count = 1;

        while ((i + 1 < len) && res[i] == res[i + 1]) {
          count++;
          i++;
        }

        cur.push_back('0' + count);
        cur.push_back(res[i]);
        i++;
      }

      res = cur;
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(CountAndSay, CountAndSay_1) {
  Solution s;
  EXPECT_EQ(s.countAndSay(1), "1");
}

TEST(CountAndSay, CountAndSay_2) {
  Solution s;
  EXPECT_EQ(s.countAndSay(2), "11");
}

TEST(CountAndSay, CountAndSay_3) {
  Solution s;
  EXPECT_EQ(s.countAndSay(3), "21");
}

TEST(CountAndSay, CountAndSay_4) {
  Solution s;
  EXPECT_EQ(s.countAndSay(4), "1211");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}