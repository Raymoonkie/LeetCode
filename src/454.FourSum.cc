#include "headers.h"

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> m;
    for (auto a : A) {
      for (auto b : B) {
        m[a + b]++;
      }
    }

    int count = 0;
    for (auto c : C) {
      for (auto d : D) {
        auto it = m.find(-c - d);
        if (it != m.end()) {
          count += it->second;
        }
      }
    }

    return count;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FourSum, FourSum_1) {
  Solution s;
  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};
  int ans = 2;
  EXPECT_EQ(s.fourSumCount(A, B, C, D), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}