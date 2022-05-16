#include "headers.h"

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    return s1(beginWord, endWord, wordList);
  }

  int s1(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    int ladder = 1;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string word = q.front();
        q.pop();

        if (word == endWord) return ladder;

        dict.erase(word);
        for (int j = 0; j < word.size(); j++) {
          char c = word[j];
          for (int k = 0; k < 26; k++) {
            word[j] = 'a' + k;

            if (dict.find(word) != dict.end()) {
              q.push(word);  // copy
            }
          }
          word[j] = c;
        }
      }
      ladder++;
    }

    return 0;
  }

  int s2(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return 0;

    unordered_set<string> head, tail, *phead, *ptail;
    head.insert(beginWord);
    tail.insert(endWord);
    int ladder = 2;
    while (!head.empty() && !tail.empty()) {
      // from small set to big set
      if (head.size() < tail.size()) {
        phead = &head;
        ptail = &tail;
      } else {
        phead = &tail;
        ptail = &head;
      }

      unordered_set<string> tmp;
      for (auto it = phead->begin(); it != phead->end(); it++) {
        string word = *it;
        for (int i = 0; i < word.size(); i++) {
          char c = word[i];
          for (int j = 0; j < 26; j++) {
            word[i] = 'a' + j;
            if (ptail->find(word) != ptail->end()) {
              return ladder;
            }

            if (dict.find(word) != dict.end()) {
              tmp.insert(word);
              dict.erase(word);
            }
          }
          word[i] = c;
        }
      }
      ladder++;
      phead->swap(tmp);
    }

    return 0;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(WordLadder, WordLadder_1) {
  Solution s;
  vector<string> in = {"hot", "dot", "dog", "lot", "log", "cog"};
  string beginWord = "hit";
  string endWord = "cog";
  int ans = 5;
  EXPECT_EQ(s.s1(beginWord, endWord, in), ans);
  EXPECT_EQ(s.s2(beginWord, endWord, in), ans);
}

TEST(WordLadder, WordLadder_2) {
  Solution s;
  vector<string> in = {"hot","dot","dog","lot","log"};
  string beginWord = "hit";
  string endWord = "cog";
  int ans = 0;
  EXPECT_EQ(s.s1(beginWord, endWord, in), ans);
  EXPECT_EQ(s.s2(beginWord, endWord, in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}