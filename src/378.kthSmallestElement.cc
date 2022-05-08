#include "headers.h"

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1], mid;
    while (l < r) {
      mid = l + (r - l) / 2;

      int count = 0;
      for (int i = 0; i < n; i++) {
        count += upper_bound(begin(matrix[i]), end(matrix[i]), mid) -
                 begin(matrix[i]);
      }

      if (count < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(kthSmallestElement, kthSmallestElement_1) {
  Solution s;
  vector<vector<int>> in = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  int ans = 13;
  EXPECT_EQ(s.kthSmallest(in, 8), ans);
}

TEST(kthSmallestElement, kthSmallestElement_2) {
  Solution s;
  vector<vector<int>> in = {{-5}};
  int ans = -5;
  EXPECT_EQ(s.kthSmallest(in, 1), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}