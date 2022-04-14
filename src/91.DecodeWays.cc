#include "headers.h"

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n+1, 0);

    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '0') {
        dp[i] += dp[i + 1];
      }

      if (i + 1 < n && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
        dp[i] += dp[i + 2];
      }
    }

    return dp[0];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(DecodeWays, DecodeWays_1) {
  Solution s;
  EXPECT_EQ(s.numDecodings("12"), 2);
}

TEST(DecodeWays, DecodeWays_2) {
  Solution s;
  EXPECT_EQ(s.numDecodings("226"), 3);
}

TEST(DecodeWays, DecodeWays_3) {
  Solution s;
  EXPECT_EQ(s.numDecodings("06"), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}