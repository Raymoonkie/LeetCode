#include "headers.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
      string t = s;
      // origin sort seem to be more faster
      sort(t.begin(), t.end());
      mp[t].push_back(s);
    }

    vector<vector<string>> res;
    res.reserve(mp.size());

    for (auto& m : mp) {
      res.push_back(move(m.second));
    }

    return res;
  }

  string hash(string s) {
    int letters[26] = {0};
    for (char c : s) {
      letters[c - 'a']++;
    }

    string res = "";
    for (int c = 0; c < 26; c++) {
      res += string(letters[c], 'a' + c);
    }

    return res;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(GroupAnagrams, GroupAnagrams_1) {
  Solution s;
  vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans = {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
  EXPECT_EQ(s.groupAnagrams(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}