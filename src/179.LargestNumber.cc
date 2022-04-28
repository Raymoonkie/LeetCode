#include "headers.h"

bool compare(string& s1, string& s2) { return s1 + s2 > s2 + s1; }
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> dict;
    for (int num : nums) dict.push_back(to_string(num));
    sort(dict.begin(), dict.end(), compare);

    string res;
    for (string num : dict) {
      res += num;
    }

    return res[0] == '0' ? "0" : res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LargestNumber, LargestNumber_1) {
  Solution s;
  vector<int> in1 = {10, 2};
  EXPECT_EQ(s.largestNumber(in1), "210");
  vector<int> in2 = {3, 30, 34, 5, 9};
  EXPECT_EQ(s.largestNumber(in2), "9534330");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}