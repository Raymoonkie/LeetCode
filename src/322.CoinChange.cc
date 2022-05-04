#include "headers.h"

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) { return s1(coins, amount); }

  int s1(vector<int>& coins, int amount) {
    int count = recurse1(coins, amount, coins.size());
    return count == INT_MAX - 1 ? -1 : count;
  }

  int recurse1(vector<int>& coins, int amount, int n) {
    if (amount == 0) return 0;
    if (n == 0) return INT_MAX - 1;

    if (coins[n - 1] > amount) {
      return recurse1(coins, amount, n - 1);
    } else {
      return min(recurse1(coins, amount, n - 1),
                 1 + recurse1(coins, amount - coins[n - 1], n));
    }
  }

  int s2(vector<int>& coins, int amount) {
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, INT_MAX));
    int count = recurse2(coins, amount, coins.size(), dp);
    return count == INT_MAX ? -1 : count;
  }

  int recurse2(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
    if (amount == 0) return 0;
    if (n == 0) return INT_MAX;
    if (dp[amount][n] != INT_MAX) return dp[amount][n];

    dp[amount][n] = recurse2(coins, amount, n - 1, dp);

    if (amount - coins[n - 1] >= 0) {
      int tmp = recurse2(coins, amount - coins[n - 1], n, dp);
      if (tmp != INT_MAX) {
        dp[amount][n] = min(dp[amount][n], 1 + tmp);
      }
    }

    return dp[amount][n];
  }

  int s3(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(amount + 1, vector<int>(n + 1, amount + 1));
    for (int i = 1; i <= amount; i++) {
      dp[i][0] = amount + 1;
    }

    for (int j = 0; j <= n; j++) {
      dp[0][j] = 0;
    }

    for (int i = 1; i <= amount; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i][j - 1];
        if (i - coins[j - 1] >= 0) {
          dp[i][j] = min(dp[i][j - 1], 1 + dp[i - coins[j - 1]][j]);
        }
      }
    }

    return dp[amount][n] == amount + 1 ? -1 : dp[amount][n];
  }

  int s4(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0) {
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
      }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(CoinChange, CoinChange_1) {
  Solution s;
  vector<int> in = {1, 2, 5};
  int ans = 3;
  EXPECT_EQ(s.s1(in, 11), ans);
  EXPECT_EQ(s.s2(in, 11), ans);
  EXPECT_EQ(s.s3(in, 11), ans);
  EXPECT_EQ(s.s4(in, 11), ans);
}

TEST(CoinChange, CoinChange_2) {
  Solution s;
  vector<int> in = {2};
  int ans = -1;
  EXPECT_EQ(s.s1(in, 3), ans);
  EXPECT_EQ(s.s2(in, 3), ans);
  EXPECT_EQ(s.s3(in, 3), ans);
  EXPECT_EQ(s.s4(in, 3), ans);
}

TEST(CoinChange, CoinChange_3) {
  Solution s;
  vector<int> in = {1};
  int ans = 0;
  EXPECT_EQ(s.s1(in, 0), ans);
  EXPECT_EQ(s.s2(in, 0), ans);
  EXPECT_EQ(s.s3(in, 0), ans);
  EXPECT_EQ(s.s4(in, 0), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}