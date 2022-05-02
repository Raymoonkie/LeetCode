#include "headers.h"

class Solution {
 public:
  int numSquares(int n) { return s1(n); }

  int s1(int n) {
    static vector<int> backup{0};
    backup[0] = 0;

    while (backup.size() <= n) {
      int m = backup.size();

      int count = INT_MAX;
      for (int i = 1; i * i <= m; i++) {
        count = min(count, backup[m - i * i] + 1);
      }
      backup.push_back(count);
    }

    return backup[n];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(PerfectSquares, PerfectSquares_1) {
  Solution s;
  EXPECT_EQ(s.numSquares(12), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}