#include "headers.h"

struct Trie {
  void addWord(string &word) {
    Trie *cur = this;
    for (auto c : word) {
      c -= 'a';
      if (!cur->children[c]) cur->children[c] = new Trie();
      cur = cur->children[c];
    }
    cur->word = &word;
  }

  string *word;
  Trie *children[26] = {};
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size();
    int n = board[0].size();
    Trie trie;
    for (auto& word : words) {
      trie.addWord(word);
    }

    vector<string> ans;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(board, i, j, m, n, &trie, ans);
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>> &board, int i, int j, int m, int n, Trie *trie,
           vector<string> &ans) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '%' ||
        !trie->children[board[i][j] - 'a'])
      return;

    char originChar = board[i][j];

    Trie *cur = trie->children[originChar - 'a'];
    if (cur->word) {
      ans.push_back(*cur->word);
      cur->word = nullptr;  // dedup
    }

    board[i][j] = '%';
    static int DIR[5] = {0, 1, 0, -1, 0};
    for (int k = 0; k < 4; k++) {
      dfs(board, i + DIR[k], j + DIR[k + 1], m, n, cur, ans);
    }
    board[i][j] = originChar;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WordSearch, WordSearch_1) {
  Solution s;
  vector<vector<char>> in = {{'o', 'a', 'a', 'n'},
                             {'e', 't', 'a', 'e'},
                             {'i', 'h', 'k', 'r'},
                             {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<string> ans = {"oath", "eat"};
  EXPECT_EQ(s.findWords(in, words), ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}