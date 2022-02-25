#include "headers.h"

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    m--;
    n--;
    int x = m + n + 1;
    while (n >= 0) {
      if (m >= 0 && nums1[m] > nums2[n]) {
        nums1[x--] = nums1[m--];
      } else {
        nums1[x--] = nums2[n--];
      }
    }
  }
};

TEST(MergeSortedArray, MergeSortedArray_1) {
  Solution s;
  vector<int> in1 = {1, 2, 3, 0, 0, 0};
  vector<int> in2 = {2, 5, 6};
  vector<int> out = {1, 2, 2, 3, 5, 6};
  s.merge(in1, 3, in2, 3);
  EXPECT_EQ(in1, out);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}