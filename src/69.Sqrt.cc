#include "headers.h"

class Solution {
 public:
  int mySqrt(int x) {
    int left = 0;
    int right = min(x / 2 + 1, 46340);

    while (left <= right) {
      int mid = (left + right) / 2;

      int tmp = mid * mid;

      if (tmp == x) {
        return mid;
      } else if (tmp > x) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return right;
  }
};

TEST(Sqrt, Sqrt_1) {
  Solution s;

  for (long i = 2147483647 - 100000000; i <= 2147483647; i++) {
    EXPECT_EQ(s.mySqrt(i), floorf64(pow(i, 0.5)));
    if (s.mySqrt(i) < 0) {
      cout << i << endl;
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}