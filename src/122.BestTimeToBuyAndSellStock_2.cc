#include "headers.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) { return s1(prices); }

  int s1(vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) {
        maxProfit += prices[i] - prices[i - 1];
      }
    }

    return maxProfit;
  }

  int s2(vector<int>& prices) {
    int maxProfit = 0, buy = 0, sell = 0, days = prices.size();

    while (buy < days) {
      while (buy + 1 < days && prices[buy + 1] < prices[buy]) {
        buy++;
      }

      sell = buy;

      while (sell + 1 < days && prices[sell + 1] > prices[sell]) {
        sell++;
      }

      maxProfit += prices[sell] - prices[buy];
      buy = sell + 1;
    }

    return maxProfit;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(BestTimeToBuyAndSellStock_2, BestTimeToBuyAndSellStock_2_1) {
  Solution s;
  vector<int> in = {7, 1, 5, 3, 6, 4};
  int ans = 7;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

TEST(BestTimeToBuyAndSellStock_2, BestTimeToBuyAndSellStock_2_2) {
  Solution s;
  vector<int> in = {1, 2, 3, 4, 5};
  int ans = 4;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

TEST(BestTimeToBuyAndSellStock_2, BestTimeToBuyAndSellStock_2_3) {
  Solution s;
  vector<int> in = {7, 6, 4, 3, 1};
  int ans = 0;
  EXPECT_EQ(s.s1(in), ans);
  EXPECT_EQ(s.s2(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}