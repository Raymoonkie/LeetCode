#include "headers.h"

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return s4(nums, 0, nums.size() - 1, k);
  }

  int s1(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
  }

  // max heap
  int s2(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
      pq.push(num);
      if (pq.size() > k) pq.pop();
    }
    return pq.top();
  }

  // min heap
  int s3(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++) {
      pq.pop();
    }
    return pq.top();
  }

  // quick select
  int s4(vector<int>& nums, int start, int end, int k) {
    int index = partition(nums, start, end);
    if (index == k - 1)
      return nums[index];
    else if (index < k - 1)
      return s4(nums, index + 1, end, k);
    else
      return s4(nums, start, index - 1, k);
  }

  int partition(vector<int>& nums, int low, int high) {
    srand(0);
    int index = low + rand() % (high - low + 1);
    int pivot = nums[index];
    swap(nums[index], nums[high]);

    for (int i = low; i < high; i++) {
      if (nums[i] > pivot) {
        swap(nums[i], nums[low]);
        low++;
      }
    }

    swap(nums[low], nums[high]);
    return low;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(KthLargestElement, KthLargestElement_1) {
  Solution s;
  vector<int> in = {3, 2, 1, 5, 6, 4};
  int ans = 5;
  // EXPECT_EQ(s.s1(in, 2), ans);
  EXPECT_EQ(s.s2(in, 2), ans);
  EXPECT_EQ(s.s3(in, 2), ans);
  EXPECT_EQ(s.s4(in, 0, 5, 2), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}