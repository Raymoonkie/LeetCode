#include "headers.h"

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits == "") return {};
    vector<string> mappings{"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"},
        ans{""};

    for (char digit : digits) {
      vector<string> extends;
      for (string s : ans) {
        for (char letter : mappings[digit - '2']) {
          extends.push_back(s + letter);
        }
      }
      ans = move(extends);
    }
    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LetterCombinationsOfPhoneNumber, LetterCombinationsOfPhoneNumber_1) {
  Solution s;
  string in = "23";
  vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  EXPECT_EQ(s.letterCombinations(in), ans);
}

TEST(LetterCombinationsOfPhoneNumber, LetterCombinationsOfPhoneNumber_2) {
  Solution s;
  string in = "2";
  vector<string> ans = {"a", "b", "c"};
  EXPECT_EQ(s.letterCombinations(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}