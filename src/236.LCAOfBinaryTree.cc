#include "headers.h"

class Solution {
 public:
  // base on two assumption,
  // 1. both p and q exsit in tree
  // 2. p and q are unique
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root->val == p->val || root->val == q->val)
      return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;

    return left ? left : right;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(LCAOfBinaryTree, LCAOfBinaryTree_1) {
  Solution s;
  Tree tree{3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4};
  TreeNode* p = new TreeNode(5);
  TreeNode* q = new TreeNode(1);

  TreeNode* ans = new TreeNode(3);
  EXPECT_EQ(s.lowestCommonAncestor(tree.root, p, q)->val, ans->val);

  delete p;
  delete q;
  delete ans;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}