#include "headers.h"

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    queue<TreeNode*> queue;
    vector<vector<int>> res;
    queue.push(root);

    bool leftToRight = true;
    while (!queue.empty()) {
      int size = queue.size();
      vector<int> level(size);

      for (int i = 0; i < size; i++) {
        TreeNode* node = queue.front();
        queue.pop();

        int index = leftToRight ? i : size - i - 1;
        level[index] = node->val;

        if (node->left) {
          queue.push(node->left);
        }

        if (node->right) {
          queue.push(node->right);
        }
      }
      leftToRight = !leftToRight;
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

TEST(ZigZigLevelOrder, ZigZigLevelOrder_1) {
  Solution s;
  Tree tree{3, 9, 20, NULL, NULL, 15, 7};
  vector<vector<int>> ans = {{3}, {20, 9}, {15, 7}};
  EXPECT_EQ(s.zigzagLevelOrder(tree.root), ans);
}

TEST(ZigZigLevelOrder, ZigZigLevelOrder_2) {
  Solution s;
  Tree tree{1};
  vector<vector<int>> ans = {{1}};
  EXPECT_EQ(s.zigzagLevelOrder(tree.root), ans);
}

TEST(ZigZigLevelOrder, ZigZigLevelOrder_3) {
  Solution s;
  vector<vector<int>> ans = {};
  EXPECT_EQ(s.zigzagLevelOrder(nullptr), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}