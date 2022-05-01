#include "headers.h"

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) { return s1(root, k); }

  // in order traverse, O(n) Time Cost, O(n) Space Cost
  int s1(TreeNode* root, int k) {
    vector<int> sorted;
    in_order_traverse(root, sorted);

    return sorted[k - 1];
  }

  void in_order_traverse(TreeNode* root, vector<int>& sorted) {
    if (!root) return;

    in_order_traverse(root->left, sorted);
    sorted.push_back(root->val);
    in_order_traverse(root->right, sorted);
  }

  // base stack, pop out k time smallest element
  int s2(TreeNode* root, int k) {
    stack<TreeNode*> stack;
    push_left(root, stack);
    while (--k > 0) {
      TreeNode* smallest = stack.top();
      stack.pop();
      push_left(smallest->right, stack);
    }

    return stack.top()->val;
  }

  void push_left(TreeNode* root, stack<TreeNode*>& stack) {
    while (root) {
      stack.push(root);
      root = root->left;
    }
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(KthSmallestElementInBST, KthSmallestElementInBST_1) {
  Solution s;
  Tree tree{3, 1, 4, NULL, 2};
  EXPECT_EQ(s.s1(tree.root, 1), 1);
  EXPECT_EQ(s.s2(tree.root, 1), 1);
}

TEST(KthSmallestElementInBST, KthSmallestElementInBST_2) {
  Solution s;
  Tree tree{5, 3, 6, 2, 4, NULL, NULL, 1};
  EXPECT_EQ(s.s1(tree.root, 3), 3);
  EXPECT_EQ(s.s2(tree.root, 3), 3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}