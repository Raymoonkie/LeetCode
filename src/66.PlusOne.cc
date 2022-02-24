#include "headers.h"

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int index = digits.size() - 1;
    while (index >= 0) {
      if (digits[index] == 9) {
        digits[index] = 0;
      } else {
        digits[index] += 1;
        return digits;
      }

      index--;
    }
    digits.insert(digits.begin(), 1);

    return digits;
  }
};

TEST(PlusOne, PlusOne_1) {
  Solution s;
  vector<int> in = {9, 9, 9};
  vector<int> ans = {1, 0, 0, 0};
  EXPECT_EQ(s.plusOne(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}