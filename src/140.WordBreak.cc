#include "headers.h"

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> map;
    return s1(s, dict, map);
  }

  vector<string> s1(string& s, unordered_set<string>& dict,
                    unordered_map<string, vector<string>>& m) {
    if (m.count(s)) return m[s];

    vector<string> res;
    if (dict.count(s)) res.push_back(s);

    for (int i = 0; i < s.size(); i++) {
      string suffix = s.substr(i);
      if (dict.count(suffix)) {
        string prefix = s.substr(0, i);
        vector<string> tmp = combine(suffix, s1(prefix, dict, m));

        res.insert(res.end(), tmp.begin(), tmp.end());
      }
    }
    m[s] = res;

    return res;
  }

  vector<string> combine(string word, vector<string> prev) {
    for (int i = 0; i < prev.size(); ++i) {
      prev[i] += " " + word;
    }
    return prev;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WordBreak, WordBreak_1) {
  Solution s;
  string word = "catsanddog";
  vector<string> in = {"cat", "cats", "and", "sand", "dog"};
  vector<string> ans = {"cat sand dog", "cats and dog"};
  EXPECT_EQ(s.wordBreak(word, in), ans);
}

TEST(WordBreak, WordBreak_2) {
  Solution s;
  string word = "catsandog";
  vector<string> in = {"cats", "dog", "sand", "and", "cat"};
  vector<string> ans = {};
  EXPECT_EQ(s.wordBreak(word, in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}