#include "headers.h"

class Solution {
 public:
  void rotate(vector<int>& nums, int k) { return s2(nums, k); }

  void s1(vector<int>& nums, int k) {
    k = k % nums.size();
    int n = nums.size();

    int tmp = 0;
    while (k-- > 0) {
      tmp = nums[n - 1];
      for (int i = n - 1; i > 0; i--) {
        nums[i] = nums[i - 1];
      }
      nums[0] = tmp;
    }
  }

  void s2(vector<int>& nums, int k) {
    k = k % nums.size();
    int n = nums.size();

    int rotate_count = 0;
    int start_pos = 0;
    int cur_pos = start_pos;
    int last_value = nums[cur_pos];
    while (rotate_count < n) {
      do {
        int new_pos = (cur_pos + k) % n;
        int tmp = nums[new_pos];
        nums[new_pos] = last_value;
        last_value = tmp;
        cur_pos = new_pos;
        rotate_count++;
      } while (start_pos != cur_pos);

      start_pos++;
      cur_pos = start_pos;
      last_value = nums[cur_pos];
    }
  }

  void s3(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(RotateArray, RotateArray_1) {
  Solution s;
  vector<int> in = {1, 2, 3, 4, 5, 6, 7};
  vector<int> ans = {5, 6, 7, 1, 2, 3, 4};
  s.rotate(in, 3);
  EXPECT_EQ(in, ans);
}

TEST(RotateArray, RotateArray_2) {
  Solution s;
  vector<int> in = {-1, -100, 3, 99};
  vector<int> ans = {3, 99, -1, -100};
  s.rotate(in, 2);
  EXPECT_EQ(in, ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}