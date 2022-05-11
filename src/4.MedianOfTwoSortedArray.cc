#include "headers.h"

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return s1(nums1, nums2);
  }

  double s1(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    int L = (m + n - 1) / 2;
    int R = (m + n) / 2;

    if (m == 0 || n == 0) {
      return m == 0 ? (n == 0 ? 0 : ((double)nums2[L] + nums2[R]) / 2)
                    : ((double)nums1[L] + nums1[R]) / 2;
    }

    int i = 0;
    int j = 0;
    for (size_t k = 0; k < L; k++) {
      if (i >= m) {
        j++;
      } else if (j >= n) {
        i++;
      } else {
        nums1[i] < nums2[j] ? i++ : j++;
      }
    }

    double a = 0;
    if (i >= m) {
      a = nums2[j++];
    } else if (j >= n) {
      a = nums1[i++];
    } else {
      a = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    }

    double b = a;
    if (R > L) {
      if (i >= m) {
        b = nums2[j++];
      } else if (j >= n) {
        b = nums1[i++];
      } else {
        b = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
      }
    }

    return (a + b) / 2;
  }

  double s2(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 == 0 && N2 == 0) return 0;
    if (N1 < N2) return s2(nums2, nums1);

    int lo = 0;
    int hi = N2 * 2;
    while (lo <= hi) {
      int mid2 = (lo + hi) / 2;
      int mid1 = N1 + N2 - mid2;

      double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
      double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
      double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
      double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

      if (L1 > R2) {
        lo = mid2 + 1;
      } else if (L2 > R1) {
        hi = mid2 - 1;
      } else {
        return (max(L1, L2) + min(R1, R2)) / 2;
      }
    }

    return -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_1) {
  Solution s;
  vector<int> in1 = {2, 2, 2, 2};
  vector<int> in2 = {2, 2, 2};
  EXPECT_EQ(s.s1(in1, in2), 2);
  EXPECT_EQ(s.s2(in1, in2), 2);
}

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_2) {
  Solution s;
  vector<int> in1 = {1};
  vector<int> in2 = {2, 3, 4, 5};
  EXPECT_EQ(s.s1(in1, in2), 3);
  EXPECT_EQ(s.s2(in1, in2), 3);
}

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_3) {
  Solution s;
  vector<int> in1 = {1, 3, 5};
  vector<int> in2 = {2, 4, 6};
  EXPECT_EQ(s.s1(in1, in2), 3.5);
  EXPECT_EQ(s.s2(in1, in2), 3.5);
}

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_4) {
  Solution s;
  vector<int> in1 = {};
  vector<int> in2 = {1};
  EXPECT_EQ(s.s1(in1, in2), 1);
  EXPECT_EQ(s.s2(in1, in2), 1);
}

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_5) {
  Solution s;
  vector<int> in1 = {};
  vector<int> in2 = {};
  EXPECT_EQ(s.s1(in1, in2), 0);
  EXPECT_EQ(s.s2(in1, in2), 0);
}

TEST(MedianOfTwoSortedArray, MedianOfTwoSortedArray_6) {
  Solution s;
  vector<int> in1 = {};
  vector<int> in2 = {2, 3};
  EXPECT_EQ(s.s1(in1, in2), 2.5);
  EXPECT_EQ(s.s2(in1, in2), 2.5);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}