#include "headers.h"

typedef pair<int, int> pii;
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pii>> g(n + 1);
    for (const auto& t : times) g[t[0]].emplace_back(t[1], t[2]);

    const int inf = 1e9;
    vector<int> dist(n + 1, inf);
    vector<bool> visit(n + 1, false);
    dist[k] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, k);

    int u, v, w;
    while (!q.empty()) {
      u = q.top().second;
      q.pop();
      if (visit[u]) continue;
      visit[u] = true;
      for (auto& to : g[u]) {
        v = to.first;
        w = to.second;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          q.emplace(dist[v], v);
        }
      }
    }

    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == inf ? -1 : ans;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(NetworkDelayTime, NetworkDelayTime_1) {
  Solution s;
  vector<vector<int>> in = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  EXPECT_EQ(s.networkDelayTime(in, 4, 2), 2);
}

TEST(NetworkDelayTime, NetworkDelayTime_2) {
  Solution s;
  vector<vector<int>> in = {{1, 2, 1}};
  EXPECT_EQ(s.networkDelayTime(in, 2, 1), 1);
}

TEST(NetworkDelayTime, NetworkDelayTime_3) {
  Solution s;
  vector<vector<int>> in = {{1, 2, 1}};
  EXPECT_EQ(s.networkDelayTime(in, 2, 2), -1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}