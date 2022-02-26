#include "headers.h"

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }

    return isSymmetric(root->left, root->right);
  }

  bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left&& !right) {
      return true;
    }

    if (!left || !right) {
      return false;
    }

    return left->val == right->val && isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};

TEST(SymmetricTree, SymmetricTree_1) {
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

  bool ans = true;
  EXPECT_EQ(s.isSymmetric(root), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}