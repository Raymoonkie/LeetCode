#include "headers.h"

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    
    queue<TreeNode*> queue;
    vector<vector<int>> res;
    queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      vector<int> level;
      while (size > 0) {
        TreeNode* node = queue.front();
        queue.pop();
        level.push_back(node->val);

        if (node->left) {
          queue.push(node->left);
        }

        if (node->right) {
          queue.push(node->right);
        }

        size--;
      }
      res.push_back(level);
    }

    return res;
  }
};
static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(BinaryTreeLevelOrderTraversal, BinaryTreeLevelOrderTraversal_1) {
  Solution s;
  Tree tree{3, 9, 20, NULL, NULL, 15, 7};
  vector<vector<int>> ans{{3}, {9, 20}, {15, 7}};
  EXPECT_EQ(s.levelOrder(tree.root), ans);
}

TEST(BinaryTreeLevelOrderTraversal, BinaryTreeLevelOrderTraversal_2) {
  Solution s;
  Tree tree{1};
  vector<vector<int>> ans{{1}};
  EXPECT_EQ(s.levelOrder(tree.root), ans);
}

TEST(BinaryTreeLevelOrderTraversal, BinaryTreeLevelOrderTraversal_3) {
  Solution s;
  vector<vector<int>> ans{};
  EXPECT_EQ(s.levelOrder(nullptr), ans);
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}