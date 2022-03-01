#include "headers.h"

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> visited;

    for(int num: nums) {
      if (visited.count(num)) {
        return true;
      } else {
        visited.insert(num);
      }
    }

    return false;
  }
};

static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

TEST(ContainsDuplicate, ContainsDuplicate_1) {
  Solution s;
  vector<int> in = {1, 2, 3, 1};
  bool ans = true;
  EXPECT_EQ(s.containsDuplicate(in), ans);
}

TEST(ContainsDuplicate, ContainsDuplicate_2) {
  Solution s;
  vector<int> in = {1, 2, 3, 4};
  bool ans = false;
  EXPECT_EQ(s.containsDuplicate(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}