#include "headers.h"

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                          TreeNode* target) {
    if (!cloned) return nullptr;
    if (cloned->val == target->val) return cloned;
    TreeNode* l = getTargetCopy(original, cloned->left, target);
    if (l) return l;
    return getTargetCopy(original, cloned->right, target);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(FindNodeInTree, FindNodeInTree_1) {
  Solution s;
  Tree tree{7, 4, 3, NULL, NULL, 6, 19};
  TreeNode target(3);
  EXPECT_EQ(s.getTargetCopy(tree.root, tree.root, &target)->val, target.val);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}