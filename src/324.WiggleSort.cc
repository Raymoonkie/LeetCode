#include "headers.h"

class Solution {
 public:
  void wiggleSort(vector<int>& nums) { return s1(nums); }

  void s1(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> arr(n);

    int i = 1;
    int j = n - 1;

    while (i < n) {
      arr[i] = nums[j];
      j--;
      i += 2;
    }

    i = 0;
    while (i < n) {
      arr[i] = nums[j];
      j--;
      i += 2;
    }

    for (int i = 0; i < n; i++) nums[i] = arr[i];
  }

  void s2(vector<int>& nums) {
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

    int m = *(nums.begin() + n / 2);
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

    int l = 0, r = n - 1;
    int i = 0;
    while (i <= r) {
      if (A(i) > m) {
        swap(A(i), A(l));
        i++;
        l++;
      } else if (A(i) < m) {
        swap(A(i), A(r));
        r--;
      } else {
        i++;
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WiggleSort, WiggleSort_1) {
  Solution s;
  vector<int> ans = {1, 6, 1, 5, 1, 4};

  vector<int> in = {1, 5, 1, 1, 6, 4};
  s.s1(in);
  EXPECT_EQ(in, ans);

  vector<int> in2 = {1, 5, 1, 1, 6, 4};
  s.s2(in2);
  EXPECT_EQ(in2, ans);
}

TEST(WiggleSort, WiggleSort_2) {
  Solution s;
  vector<int> ans = {2, 3, 1, 3, 1, 2};

  vector<int> in = {1, 3, 2, 2, 3, 1};
  s.s1(in);
  EXPECT_EQ(in, ans);

  vector<int> in2 = {1, 3, 2, 2, 3, 1};
  s.s2(in2);
  EXPECT_EQ(in2, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}