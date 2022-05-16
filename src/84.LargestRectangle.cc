#include "headers.h"

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int max_area = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++) {
      int cur_height = i == n ? 0 : heights[i];
      while (!st.empty() && cur_height < heights[st.top()]) {
        int top = st.top();
        st.pop();

        int width = st.empty() ? i : i - st.top() - 1;
        int area = heights[top] * width;
        max_area = max(max_area, area);
      }
      st.push(i);
    }
    return max_area;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LargestRectangle, LargestRectangle_1) {
  Solution s;
  vector<int> in = {2, 1, 5, 6, 2, 3};
  int ans = 10;
  EXPECT_EQ(s.largestRectangleArea(in), ans);
}

TEST(LargestRectangle, LargestRectangle_2) {
  Solution s;
  vector<int> in = {4, 2, 0, 3, 2, 5};
  int ans = 6;
  EXPECT_EQ(s.largestRectangleArea(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}