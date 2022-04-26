#include "headers.h"

class LRUCache {
  size_t m_capacity;
  list<pair<int, int>> m_list;
  unordered_map<int, list<pair<int, int>>::iterator> m_map;

 public:
  LRUCache(int capacity) : m_capacity(capacity) {}

  int get(int key) {
    auto found_iter = m_map.find(key);
    if (found_iter == m_map.end()) return -1;
    m_list.splice(m_list.begin(), m_list, m_map[key]);

    return m_map[key]->second;
  }

  void put(int key, int value) {
    if (m_map.find(key) != m_map.end()) {
      m_list.splice(m_list.begin(), m_list, m_map[key]);
      m_map[key]->second = value;
      return;
    }

    if (m_list.size() == m_capacity) {
      auto d_key = m_list.back().first;
      m_list.pop_back();
      m_map.erase(d_key);
    }

    m_list.push_front({key, value});
    m_map[key] = m_list.begin();
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LRUCache, LRUCache_1) {
  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);             // cache is {1=1}
  lRUCache->put(2, 2);             // cache is {1=1, 2=2}
  EXPECT_EQ(1, lRUCache->get(1));  // return 1
  lRUCache->put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  EXPECT_EQ(-1, lRUCache->get(2));  // returns -1 (not found)
  lRUCache->put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  EXPECT_EQ(-1, lRUCache->get(1));  // return -1 (not found)
  EXPECT_EQ(3, lRUCache->get(3));   // return 3
  EXPECT_EQ(4, lRUCache->get(4));   // return 4
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}