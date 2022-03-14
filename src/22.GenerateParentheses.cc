#include "headers.h"

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans = {};
    backtrace(ans, "", n, n);
    return ans;
  }

  void backtrace(vector<string> &res, string str, int left, int right) {
    if (left == 0 && right == 0) {
      res.push_back(str);
      return;
    }

    if (left) backtrace(res, str + "(", left - 1, right);
    if (right > left) backtrace(res, str + ")", left, right - 1);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(GenerateParentheses, GenerateParentheses_1) {
  Solution s;
  vector<string> ans = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  EXPECT_EQ(s.generateParenthesis(3), ans);
}

TEST(GenerateParentheses, GenerateParentheses_2) {
  Solution s;
  vector<string> ans = {"()"};
  EXPECT_EQ(s.generateParenthesis(1), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}