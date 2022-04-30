#include "headers.h"

class Solution {
 public:
  vector<int> findOrder(int N, vector<vector<int>>& P) { return s2(N, P); }

  // bfs
  vector<int> s1(int N, vector<vector<int>>& P) {
    vector<vector<int>> g(N);
    vector<int> degrees(N);

    for (auto edge : P) {
      g[edge[1]].push_back(edge[0]);
      degrees[edge[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
      if (degrees[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      ans.push_back(cur);

      for (auto next : g[cur]) {
        if (--degrees[next] == 0) {
          q.push(next);
        }
      }
    }

    if (ans.size() == N) return ans;
    return {};
  }

  vector<int> s2(int N, vector<vector<int>>& P) {
    vector<vector<int>> g(N);
    vector<int> degrees(N);

    for (auto edge : P) {
      g[edge[1]].push_back(edge[0]);
      degrees[edge[0]]++;
    }

    vector<int> ans;
    function<void(int)> dfs = [&](int cur) {
      ans.push_back(cur);
      degrees[cur] = -1;
      for (auto next : g[cur]) {
        if (--degrees[next] == 0) {
          dfs(next);
        }
      }
    };

    for (int i = 0; i < N; i++) {
      if (degrees[i] == 0) {
        dfs(i);
      }
    }

    if (ans.size() == N) return ans;
    return {};
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(CourseSchedule, CourseSchedule_1) {
  Solution s;
  vector<vector<int>> in = {{1, 0}};
  vector<int> ans = {0, 1};
  EXPECT_EQ(s.s1(2, in), ans);
  EXPECT_EQ(s.s2(2, in), ans);
}

TEST(CourseSchedule, CourseSchedule_2) {
  Solution s;
  vector<vector<int>> in = {{1, 0}, {{0, 1}}};
  vector<int> ans = {};
  EXPECT_EQ(s.s1(2, in), ans);
  EXPECT_EQ(s.s2(2, in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}