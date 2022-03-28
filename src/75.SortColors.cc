#include "headers.h"

class Solution {
 public:
  void sortColors(vector<int>& nums) { one_pass(nums); }

  void count_replace(vector<int>& nums) {
    int colors[3] = {0};

    for (int i = 0; i < nums.size(); i++) {
      colors[nums[i]]++;
    }

    int index = 0;
    while (colors[0] > 0) {
      nums[index] = 0;
      index++;
      colors[0]--;
    }

    while (colors[1] > 0) {
      nums[index] = 1;
      index++;
      colors[1]--;
    }

    while (colors[2] > 0) {
      nums[index] = 2;
      index++;
      colors[2]--;
    }
  }

  void one_pass(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SortColors, SortColors_1) {
  Solution s;
  vector<int> in = {2, 0, 2, 1, 1, 0};
  vector<int> ans = {0, 0, 1, 1, 2, 2};

  s.sortColors(in);
  EXPECT_EQ(in, ans);
}

TEST(SortColors, SortColors_2) {
  Solution s;
  vector<int> in = {2, 0, 1};
  vector<int> ans = {0, 1, 2};

  s.sortColors(in);
  EXPECT_EQ(in, ans);
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}