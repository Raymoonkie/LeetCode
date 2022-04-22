#include "headers.h"

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    return greedy(gas, cost);
  }

  int brute_force(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    for (int i = 0; i < n; i++) {
      int gasLeft = 0;
      int stationLeft = n;
      int j = i;
      while (stationLeft > 0) {
        gasLeft += (gas[j % n] - cost[j % n]);
        if (gasLeft < 0) break;
        stationLeft--;
        j++;
      }

      if (stationLeft == 0 && gasLeft >= 0) return i;
    }

    return -1;
  }

  int greedy(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int total_gas = 0;
    int total_cost = 0;

    int start = 0;
    int gas_cost_from_start = 0;
    for (int i = 0; i < n; i++) {
      total_cost += cost[i];
      total_gas += gas[i];

      gas_cost_from_start += (gas[i] - cost[i]);
      if (gas_cost_from_start < 0) {
        start = i + 1;
        gas_cost_from_start = 0;
      }
    }

    return total_cost <= total_gas ? start : -1;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(GasStation, GasStation_1) {
  Solution s;
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  int ans = 3;
  EXPECT_EQ(s.brute_force(gas, cost), ans);
  EXPECT_EQ(s.greedy(gas, cost), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}