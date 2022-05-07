#include "headers.h"

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto num : nums) m[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    for (auto it : m) {
      q.push({it.second, it.first});
      if (q.size() > k) q.pop();
    }

    vector<int> ans;
    while (k--) {
      ans.push_back(q.top().second);
      q.pop();
    }

    return ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(TopKFrequentElements, TopKFrequentElements_1) {
  Solution s;
  vector<int> in = {1, 1, 1, 2, 2, 3};
  vector<int> ans = {2, 1};
  EXPECT_EQ(s.topKFrequent(in, 2), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}