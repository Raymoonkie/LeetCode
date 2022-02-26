#include "headers.h"

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

TEST(MaxDepthOfBinaryTree, MaxDepthOfBinaryTree_1) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);

  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  node2->left = node4;
  node2->right = node3;

  int ans = 3;
  EXPECT_EQ(s.maxDepth(root), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}