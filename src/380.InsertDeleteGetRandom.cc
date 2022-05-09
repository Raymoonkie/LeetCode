#include "headers.h"

class RandomizedSet {
 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (m.find(val) != m.end()) return false;
    nums.emplace_back(val);
    m[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (m.find(val) == m.end()) return false;
    int last = nums.back();
    m[last] = m[val];
    nums[m[val]] = last;
    nums.pop_back();
    m.erase(val);
    return true;
  }

  int getRandom() { return nums[rand() % nums.size()]; }

 private:
  unordered_map<int, int> m;
  vector<int> nums;
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(InsertDeleteGetRandom, InsertDeleteGetRandom_1) {
  RandomizedSet* randomizedSet = new RandomizedSet();
  EXPECT_EQ(true, randomizedSet->insert(1));
  EXPECT_EQ(false, randomizedSet->remove(2));
  EXPECT_EQ(true, randomizedSet->insert(2));
  EXPECT_EQ(2, randomizedSet->getRandom());
  EXPECT_EQ(true, randomizedSet->remove(1));
  EXPECT_EQ(false, randomizedSet->insert(2));
  EXPECT_EQ(2, randomizedSet->getRandom());

  delete randomizedSet;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}