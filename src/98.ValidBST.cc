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
  Tree tree{2, 1, 3};
  EXPECT_EQ(s.isValidBST(tree.root), true);
}

TEST(ValidBST, ValidBST_2) {
  Solution s;
  Tree tree{5, 1, 4, NULL, NULL, 3, 6};
  EXPECT_EQ(s.isValidBST(tree.root), false);
}

TEST(ValidBST, ValidBST_3) {
  Solution s;
  Tree tree{5, 4, 6, NULL, NULL, 3, 7};
  EXPECT_EQ(s.isValidBST(tree.root), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}