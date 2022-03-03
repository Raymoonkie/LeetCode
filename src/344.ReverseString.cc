#include "headers.h"

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int p = 0;
    int q = s.size() - 1;

    while (p < q) {
      swap(s[p], s[q]);
      p++;
      q--;
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ReverseString, ReverseString_1) {
  Solution s;
  vector<char> in = {'h', 'e', 'l', 'l', 'o'};
  vector<char> ans = {'o', 'l', 'l', 'e', 'h'};
  s.reverseString(in);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}