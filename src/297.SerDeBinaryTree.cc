#include "headers.h"

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "# ";

    return to_string(root->val) + " " + serialize(root->left) +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    return build(ss);
  }

  TreeNode* build(istringstream& ss) {
    string s;
    ss >> s;

    if (s == "#") return nullptr;
    TreeNode* node = new TreeNode(std::stoi(s));
    node->left = build(ss);
    node->right = build(ss);

    return node;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SerDeBinaryTree, SerDeBinaryTree_1) {
  Tree tree{1, 2, 3, NULL, NULL, 4, 5};
  Codec obj;
  string tree_in_bytes = obj.serialize(tree.root);
  TreeNode* new_root = obj.deserialize(tree_in_bytes);
  EXPECT_EQ(true, is_same_tree(tree.root, new_root));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}