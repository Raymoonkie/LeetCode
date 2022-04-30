#include "headers.h"

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    return s2(numCourses, prerequisites);
  }

  // bfs
  bool s1(int numCourses, vector<vector<int>>& prerequisites) {
    graph g = build_graph(numCourses, prerequisites);
    vector<int> degrees = compute_in_degree(g);

    for (int i = 0; i < numCourses; i++) {
      int v = 0;
      while (v < numCourses) {
        if (!degrees[v]) break;
        v++;
      }

      // no v has 0 in degree, so exists circle;
      if (v == numCourses) {
        return false;
      }

      degrees[v]--;
      for (auto u : g[v]) degrees[u]--;
    }

    return true;
  }

  // s2
  bool s2(int numCourses, vector<vector<int>>& prerequisites) {
    graph g = build_graph(numCourses, prerequisites);

    vector<int> visit_status(g.size(), unvisited);
    for (int i = 0; i < numCourses; i++) {
      if (cycle_detect(g, visit_status, i)) return false;
    }

    return true;
  }

 private:
  typedef vector<vector<int>> graph;

  typedef enum _state { unvisited = 0, in_progress, visited } state;

  graph build_graph(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);

    for (auto edge : prerequisites) {
      g[edge[1]].push_back(edge[0]);
    }

    return g;
  }

  vector<int> compute_in_degree(graph& g) {
    vector<int> degrees(g.size(), 0);
    for (auto adj : g) {
      for (auto v : adj) {
        degrees[v]++;
      }
    }

    return degrees;
  }

  bool cycle_detect(graph& g, vector<int>& visit_status, int start) {
    if (visit_status[start] == in_progress) {
      return true;
    }

    if (visit_status[start] == unvisited) {
      visit_status[start] = in_progress;
      for (auto edge : g[start]) {
        if (cycle_detect(g, visit_status, edge)) {
          return true;
        }
      }
    }

    visit_status[start] = visited;
    return false;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(CourseSchedule, CourseSchedule_1) {
  Solution s;
  vector<vector<int>> prerequisites = {{1, 0}};
  EXPECT_EQ(s.s1(2, prerequisites), true);
  EXPECT_EQ(s.s2(2, prerequisites), true);
}

TEST(CourseSchedule, CourseSchedule_2) {
  Solution s;
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  EXPECT_EQ(s.s1(2, prerequisites), false);
  EXPECT_EQ(s.s2(2, prerequisites), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}