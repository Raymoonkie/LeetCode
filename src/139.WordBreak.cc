#include "headers.h"

struct TrieNode {
 public:
  bool isWord;
  TrieNode* child[26];

  TrieNode() {
    memset(child, 0, sizeof(child));
    isWord = false;
  }

  void addWord(string& s) {
    TrieNode* cur = this;
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (!cur->child[c]) cur->child[c] = new TrieNode;
      cur = cur->child[c];
    }
    cur->isWord = true;
  }
};

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) { return s3(s, wordDict); }

  // DFS
  bool s1(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> set(std::make_move_iterator(wordDict.begin()),
                              std::make_move_iterator(wordDict.end()));
    return dfs(s, 0, n, set);
  }

  bool dfs(string& s, int start, int end, unordered_set<string>& set) {
    if (start == end) return true;
    for (int i = start + 1; i <= end; i++) {
      string word = s.substr(start, i - start);

      if (set.count(word) == 1 && dfs(s, i, end, set)) {
        return true;
      }
    }

    return false;
  }

  // bootom up dp
  bool s2(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> set(std::make_move_iterator(wordDict.begin()),
                              std::make_move_iterator(wordDict.end()));
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j]) {
          string word = s.substr(j, i - j);
          if (set.count(word) == 1) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[n];
  }

  bool s3(string s, vector<string>& wordDict) {
    int n = s.length();
    TrieNode* root = new TrieNode();
    for (string word : wordDict) {
      root->addWord(word);
    }

    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
      TrieNode* cur = root;
      for (int j = i + 1; j <= n; j++) {
        int c = s[j - 1] - 'a';
        if (!cur->child[c]) break;
        cur = cur->child[c];

        if (cur->isWord && dp[j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[0];
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WordBreak, WordBreak_1) {
  Solution s;
  vector<string> wordDict1 = {"apple", "pen"};
  EXPECT_EQ(s.s1("applepenapple", wordDict1), true);

  vector<string> wordDict2 = {"apple", "pen"};
  EXPECT_EQ(s.s2("applepenapple", wordDict2), true);

  vector<string> wordDict3 = {"apple", "pen"};
  EXPECT_EQ(s.s3("applepenapple", wordDict3), true);
}

TEST(WordBreak, WordBreak_2) {
  Solution s;
  vector<string> wordDict1 = {"leet", "code"};
  EXPECT_EQ(s.s1("leetcode", wordDict1), true);

  vector<string> wordDict2 = {"leet", "code"};
  EXPECT_EQ(s.s2("leetcode", wordDict2), true);

  vector<string> wordDict3 = {"leet", "code"};
  EXPECT_EQ(s.s3("leetcode", wordDict3), true);
}

TEST(WordBreak, WordBreak_3) {
  Solution s;
  vector<string> wordDict1 = {"cats", "dog", "sand", "and", "cat"};
  EXPECT_EQ(s.s1("catsandog", wordDict1), false);

  vector<string> wordDict2 = {"cats", "dog", "sand", "and", "cat"};
  EXPECT_EQ(s.s2("catsandog", wordDict2), false);

  vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
  EXPECT_EQ(s.s3("catsandog", wordDict3), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}