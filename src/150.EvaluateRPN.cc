#include "headers.h"

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;

    int a, b;
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+") {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        s.push(b + a);
      } else if (tokens[i] == "-") {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        s.push(b - a);
      } else if (tokens[i] == "*") {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        s.push(b * a);
      } else if (tokens[i] == "/") {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        s.push(b / a);
      } else {
        s.push(std::stoi(tokens[i]));
      }
    }

    return s.top();
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(EvaluateRPN, EvaluateRPN_1) {
  Solution s;
  vector<string> in = {"2", "1", "+", "3", "*"};
  int ans = 9;
  EXPECT_EQ(s.evalRPN(in), ans);
}

TEST(EvaluateRPN, EvaluateRPN_2) {
  Solution s;
  vector<string> in = {"10", "6", "9",  "3", "+", "-11", "*",
                       "/",  "*", "17", "+", "5", "+"};
  int ans = 22;
  EXPECT_EQ(s.evalRPN(in), ans);
}

TEST(EvaluateRPN, EvaluateRPN_3) {
  Solution s;
  vector<string> in = {"2", "1", "+", "3", "*"};
  int ans = 9;
  EXPECT_EQ(s.evalRPN(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}