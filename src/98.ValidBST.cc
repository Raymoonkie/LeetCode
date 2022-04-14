#include "headers.h"

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }

  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if (minNode && root->val <= minNode->val ||
        maxNode && root->val >= maxNode->val)
      return false;

    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ValidBST, ValidBST_1) {
  Solution s;
  TreeNode* root = new TreeNode(2);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(3);
  root->left = node1;
  root->right = node2;

  EXPECT_EQ(s.isValidBST(root), true);
}

TEST(ValidBST, ValidBST_2) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(4);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(6);
  root->left = node1;
  root->right = node2;
  node2->left = node3;
  node2->right = node4;

  EXPECT_EQ(s.isValidBST(root), false);
}

TEST(ValidBST, ValidBST_3) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  TreeNode* node1 = new TreeNode(4);
  TreeNode* node2 = new TreeNode(6);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(7);
  root->left = node1;
  root->right = node2;
  node2->left = node3;
  node2->right = node4;

  EXPECT_EQ(s.isValidBST(root), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}