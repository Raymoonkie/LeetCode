#include "headers.h"

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int bitset[1005] = {0};
    for (int num : nums1) {
      bitset[num]++;
    }

    vector<int> ans;
    for (int num : nums2) {
      if (bitset[num]) {
        ans.push_back(num);
        bitset[num]--;
      }
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(IntersectionOfTwoArrays, IntersectionOfTwoArrays_1) {
  Solution s;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> ans = {2, 2};
  EXPECT_EQ(s.intersect(nums1, nums2), ans);
}

TEST(IntersectionOfTwoArrays, IntersectionOfTwoArrays_2) {
  Solution s;
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  vector<int> ans = {9, 4};
  EXPECT_EQ(s.intersect(nums1, nums2), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}