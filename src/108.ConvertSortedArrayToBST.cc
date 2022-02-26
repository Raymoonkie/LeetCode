#include "headers.h"

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
  }

  TreeNode* build(vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, start, mid - 1);
    root->right = build(nums, mid + 1, end);

    return root;
  }
};

TEST(ConvertSortedArrayToBST, ConvertSortedArrayToBST_1) {
  Solution s;
  vector<int> in = {-10, -3, 0, 5, 9};

  TreeNode* root = new TreeNode(0);
  TreeNode* node1 = new TreeNode(-10);
  TreeNode* node2 = new TreeNode(5);
  TreeNode* node3 = new TreeNode(-3);
  TreeNode* node4 = new TreeNode(9);

  root->left = node1;
  root->right = node2;
  node1->right = node3;
  node2->right = node4;
  EXPECT_EQ(is_same_tree(s.sortedArrayToBST(in), root), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}