#include "headers.h"

class Solution {
 public:
  int countPrimes(int n) { return s2(n); }

  int s1(int n) {
    if (n < 2) return 0;

    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime(i)) count++;
    }

    return count;
  }

  bool isPrime(int k) {
    int bound = sqrt(k);
    for (int j = 2; j <= bound; j++) {
      if (k % j == 0) {
        return false;
      }
    }

    return true;
  }

  int s2(int n) {
    if (n <= 1) return 0;
    vector<bool> prime(n, true);

    int count = 0;
    for (int i = 2; i < n; i++) {
      if (prime[i]) {
        count++;
        for (int j = i + i; j < n; j += i) {
          prime[j] = false;
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

TEST(CountPrimes, CountPrimes_1) {
  Solution s;
  EXPECT_EQ(s.s1(10), 4);
  EXPECT_EQ(s.s1(2), 0);
  EXPECT_EQ(s.s1(3), 1);
  EXPECT_EQ(s.s2(10), 4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}