#include "headers.h"

class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    int deepest = 0, sum = 0;
    return s2(root, deepest, sum);
  }

  int s1(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      int sum = 0;
      while (size-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        sum += node->val;
      }

      // already reach last level
      if (q.empty()) {
        return sum;
      }
    }

    return -1;
  }

  int s2(TreeNode* root, int& deepest, int& sum, int depth = 0) {
    if (!root) return 0;

    if (!root->left && !root->right) {
      if (depth == deepest)
        sum += root->val;
      else if (depth > deepest) {
        sum = root->val;
        deepest = depth;
      }
    }

    s2(root->left, deepest, sum, depth + 1);
    s2(root->right, deepest, sum, depth + 1);

    return sum;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(DeepestLeavesSum, DeepestLeavesSum_1) {
  Solution s;
  Tree tree{1, 2, 3, 4, 5, NULL, 6, 7, NULL, NULL, NULL, NULL, 8};
  int ans = 15;
  EXPECT_EQ(s.s1(tree.root), ans);

  int deepest = 0, sum = 0;
  EXPECT_EQ(s.s2(tree.root, deepest, sum), ans);
}

TEST(DeepestLeavesSum, DeepestLeavesSum_2) {
  Solution s;
  Tree tree{6, 7, 8, 2, 7, 1, 3, 9, NULL, 1, 4, NULL, NULL, NULL, 5};
  int ans = 19;
  EXPECT_EQ(s.s1(tree.root), ans);
  int deepest = 0, sum = 0;
  EXPECT_EQ(s.s2(tree.root, deepest, sum), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}