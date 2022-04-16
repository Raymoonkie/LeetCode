#include "headers.h"

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;

    unordered_map<int,int> hmap;
    for(int i = 0;i < inorder.size(); i++) {
      hmap[inorder[i]] = i;
    }
    return build(preorder, inorder, index, 0, preorder.size() - 1, hmap);
  }

  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index,
                  int left, int right, unordered_map<int,int>& hmap) {
    if (left > right) return nullptr;

    int pivot = hmap[preorder[index]];

    TreeNode* node = new TreeNode(preorder[index]);
    index++;
    node->left = build(preorder, inorder, index, left, pivot - 1, hmap);
    node->right = build(preorder, inorder, index, pivot + 1, right, hmap);

    return node;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(ConstructBinaryTree, ConstructBinaryTree_1) {
  Solution s;
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  Tree tree{3, 9, 20, NULL, NULL, 15, 7};
  EXPECT_EQ(true, is_same_tree(tree.root, s.buildTree(preorder, inorder)));
}

TEST(ConstructBinaryTree, ConstructBinaryTree_2) {
  Solution s;
  vector<int> preorder = {-1};
  vector<int> inorder = {-1};
  Tree tree{-1};
  EXPECT_EQ(true, is_same_tree(tree.root, s.buildTree(preorder, inorder)));
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}