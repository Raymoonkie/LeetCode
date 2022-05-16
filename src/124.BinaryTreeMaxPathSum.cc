#include "headers.h"

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    s1(root, ans);
    return ans;
  }

  int s1(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = max(s1(root->left, ans), 0);
    int r = max(s1(root->right, ans), 0);
    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(BinaryTreeMaxPathSum, BinaryTreeMaxPathSum_1) {
  Solution s;
  Tree tree{1, 2, 3};
  int ans = 6;
  EXPECT_EQ(s.maxPathSum(tree.root), ans);
}

TEST(BinaryTreeMaxPathSum, BinaryTreeMaxPathSum_2) {
  Solution s;
  Tree tree{-10, 9, 20, NULL, NULL, 15, 7};
  int ans = 42;
  EXPECT_EQ(s.maxPathSum(tree.root), ans);
}

TEST(BinaryTreeMaxPathSum, BinaryTreeMaxPathSum_3) {
  Solution s;
  Tree tree{-10};
  int ans = -10;
  EXPECT_EQ(s.maxPathSum(tree.root), ans);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}