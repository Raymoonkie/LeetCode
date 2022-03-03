#include "headers.h"

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
      bool f1 = i % 3 == 0;
      bool f2 = i % 5 == 0;

      if (f1 && f2) {
        ans.push_back("FizzBuzz");
      } else if (f1) {
        ans.push_back("Fizz");
      } else if (f2) {
        ans.push_back("Buzz");
      } else {
        ans.push_back(to_string(i));
      }
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FizzBuzz, FizzBuzz_1) {
  Solution s;
  int in = 3;
  vector<string> ans = {"1", "2", "Fizz"};
  EXPECT_EQ(s.fizzBuzz(in), ans);
}

TEST(FizzBuzz, FizzBuzz_2) {
  Solution s;
  int in = 5;
  vector<string> ans = {"1","2","Fizz","4","Buzz"};
  EXPECT_EQ(s.fizzBuzz(in), ans);
}


TEST(FizzBuzz, FizzBuzz_3) {
  Solution s;
  int in = 15;
  vector<string> ans = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
  EXPECT_EQ(s.fizzBuzz(in), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}