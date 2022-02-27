#include "headers.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int low_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      low_price = min(low_price, prices[i]);
      max_profit = max (max_profit, prices[i]- low_price);
    }

    return max_profit;
  }
};

TEST(BestTimeToBuyAndSellStock, BestTimeToBuyAndSellStock_1) {
  Solution s;
  vector<int> in = {7, 1, 5, 3, 6, 4};
  int ans = 5;
  EXPECT_EQ(s.maxProfit(in), ans);

  vector<int> in2 = {2, 4, 1};
  int ans2 = 2;
  EXPECT_EQ(s.maxProfit(in2), ans2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}