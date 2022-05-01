#include "headers.h"

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }

    int p = 1;
    for (int i = n - 1; i >= 0; i--) {
      ans[i] *= p;
      p *= nums[i];
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ProductOfArrayExceptSelf, ProductOfArrayExceptSelf_2) {
  Solution s;
  vector<int> in = {1, 2, 3, 4};
  vector<int> ans = {24, 12, 8, 6};
  EXPECT_EQ(s.productExceptSelf(in), ans);
}

TEST(ProductOfArrayExceptSelf, ProductOfArrayExceptSelf_1) {
  Solution s;
  vector<int> in = {-1, 1, 0, -3, 3};
  vector<int> ans = {0, 0, 9, 0, 0};
  EXPECT_EQ(s.productExceptSelf(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}