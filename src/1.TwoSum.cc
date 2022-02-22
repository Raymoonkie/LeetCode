#include "headers.h"

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> index;

    std::vector<int> out;

    int size = nums.size();
    for (int i = 0; i < size; i++) {
      unordered_map<int, int>::iterator x = index.find(target - nums[i]);
      if (x == index.end()) {
        index.insert(std::make_pair(nums[i], i));
      } else {
        out.push_back(i);
        out.push_back(x->second);
        return out;
      }
    }

    return out;
  }
};

TEST(TwoSum, TwoSum_1) {
  Solution s;
  vector<int> in = {1, 2, 3};
  vector<int> out = s.twoSum(in, 4);
  vector<int> expect = {2, 0};

  EXPECT_EQ(expect.size(), out.size());

  for (int i = 0; i < expect.size(); i++) {
    EXPECT_EQ(expect[i], out[i]);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}