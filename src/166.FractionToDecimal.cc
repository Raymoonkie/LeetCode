#include "headers.h"

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (!numerator) return "0";
    string res;

    if (numerator < 0 ^ denominator < 0) {
      res += "-";
    }

    long n = abs(numerator);
    long d = abs(denominator);

    res += to_string(n / d);
    long r = n % d;
    if (!r) {
      return res;
    }

    res += ".";

    unordered_map<long, int> m;
    while (r) {
      if (m.count(r) == 1) {
        res.insert(m[r], "(");
        res += ')';
        break;
      }

      m[r] = res.size();
      r *= 10;
      res += to_string(r / d);

      r %= d;
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FractionToDecimal, FractionToDecimal_1) {
  Solution s;
  EXPECT_EQ(s.fractionToDecimal(1, 2), "0.5");
}

TEST(FractionToDecimal, FractionToDecimal_2) {
  Solution s;
  EXPECT_EQ(s.fractionToDecimal(2, 1), "2");
}

TEST(FractionToDecimal, FractionToDecimal_3) {
  Solution s;
  EXPECT_EQ(s.fractionToDecimal(4, 333), "0.(012)");
}

TEST(FractionToDecimal, FractionToDecimal_4) {
  Solution s;
  EXPECT_EQ(s.fractionToDecimal(0, -5), "0");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}