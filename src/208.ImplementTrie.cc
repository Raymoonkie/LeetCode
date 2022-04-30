#include "headers.h"

class Trie {
 public:
  Trie() {
    isWord = false;
    memset(child, 0, sizeof(child));
  }

  void insert(string s) {
    Trie* cur = this;
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (!cur->child[c]) cur->child[c] = new Trie;
      cur = cur->child[c];
    }
    cur->isWord = true;
  }

  bool search(string s) {
    Trie* cur = this;
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (!cur->child[c]) return false;
      cur = cur->child[c];
    }
    return cur->isWord;
  }

  bool startsWith(string s) {
    Trie* cur = this;
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      if (!cur->child[c]) return false;
      cur = cur->child[c];
    }
    return true;
  }

 private:
  bool isWord;
  Trie* child[26];
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ImplementTrie, ImplementTrie_1) {
  Trie trie;
  trie.insert("apple");
  EXPECT_EQ(true, trie.search("apple"));    // return True
  EXPECT_EQ(false, trie.search("app"));     // return False
  EXPECT_EQ(true, trie.startsWith("app"));  // return True
  trie.insert("app");
  EXPECT_EQ(true, trie.search("app"));  // return True
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}