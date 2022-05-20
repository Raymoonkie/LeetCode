#include "headers.h"

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> vals;

    for (int i = 0; i < n; i++) {
      vals.emplace_back(nums[i], i);
    }

    vector<int> result(n, 0);
    vector<pair<int, int>> merged(n);
    merge_sort_count(vals, 0, n - 1, result, merged);

    return result;
  }

  void merge_sort_count(vector<pair<int, int>>& vals, int l, int r,
                        vector<int>& result, vector<pair<int, int>>& merged) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort_count(vals, l, mid, result, merged);
    merge_sort_count(vals, mid + 1, r, result, merged);

    int l_begin = l;
    int r_begin = mid + 1;
    int r_less_l_counter = 0;
    int idx = 0;
    while (l_begin <= mid && r_begin <= r) {
      if (vals[l_begin].first <= vals[r_begin].first) {
        merged[idx++] = vals[l_begin];
        result[vals[l_begin].second] += r_less_l_counter;
        l_begin++;
      } else {
        merged[idx++] = vals[r_begin];
        r_begin++;
        r_less_l_counter++;
      }
    }

    while (l_begin <= mid) {
      merged[idx++] = vals[l_begin];
      result[vals[l_begin].second] += r_less_l_counter;
      l_begin++;
    }

    while (r_begin <= r) {
      merged[idx++] = vals[r_begin];
      r_begin++;
    }

    for (int i = 0; i < idx; i++) {
      vals[l + i].first = merged[i].first;
      vals[l + i].second = merged[i].second;
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(CountOfSmallerNumAfterSelf, CountOfSmallerNumAfterSelf_1) {
  Solution s;
  vector<int> in = {5, 2, 6, 1};
  vector<int> ans = {2, 1, 1, 0};
  EXPECT_EQ(s.countSmaller(in), ans);
}

TEST(CountOfSmallerNumAfterSelf, CountOfSmallerNumAfterSelf_2) {
  Solution s;
  vector<int> in = {-1, -1};
  vector<int> ans = {0, 0};
  EXPECT_EQ(s.countSmaller(in), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}