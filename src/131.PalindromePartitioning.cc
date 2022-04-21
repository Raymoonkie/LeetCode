#include "headers.h"

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    dfs(result, path, s, 0);

    return result;
  }

  void dfs(vector<vector<string>>& result, vector<string>& path, string& s,
           int start) {
    if (start == s.length()) {
      result.push_back(path);
      return;
    }

    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        path.push_back(s.substr(start, i - start + 1));
        dfs(result, path, s, i + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }

    return true;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(PalindromePartitioning, PalindromePartitioning_1) {
  Solution s;
  string in = "aab";
  vector<vector<string>> ans = {{"a", "a", "b"}, {"aa", "b"}};
  EXPECT_EQ(s.partition(in), ans);
}

TEST(PalindromePartitioning, PalindromePartitioning_2) {
  Solution s;
  string in = "a";
  vector<vector<string>> ans = {{"a"}};
  EXPECT_EQ(s.partition(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}