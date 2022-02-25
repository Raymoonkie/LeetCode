#include "headers.h"

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans = vector<int>();
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        ans.push_back(cur->val);
        cur = cur->right;
      } else {
        // find prev node in left sub tree
        prev = cur->left;
        while (prev->right != nullptr) {
          prev = prev->right;
        }
        prev->right = cur;

        TreeNode* tmp = cur;
        cur = cur->left;
        tmp->left = nullptr;
      }
    }

    return ans;
  }

  void inorder(TreeNode* root, vector<int>& ans) {
    if (root != nullptr) {
      inorder(root->left, ans);
      ans.push_back(root->val);
      inorder(root->right, ans);
    }
  }
};

TEST(BinaryTreeInOrderTraverse, BinaryTreeInOrderTraverse_1) {
  Solution s;
  TreeNode* root = new TreeNode(1);

  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  root->right = node1;
  node1->left = node2;

  vector<int> ans = {1, 3, 2};
  EXPECT_EQ(s.inorderTraversal(root), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}