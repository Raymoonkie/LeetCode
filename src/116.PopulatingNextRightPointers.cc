#include "headers.h"

typedef TreeNode Node;
class Solution {
 public:
  Node* connect(Node* root) { return dfs(root); }

  Node* bfs(Node* root) {
    queue<Node*> queue;
    if (root) queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        Node* node = queue.front();
        queue.pop();

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);

        if (i < size - 1) {
          node->next = queue.front();
        } else {
          node->next = nullptr;
        }
      }
    }

    return root;
  }

  Node* dfs(Node* root) {
    if (!root) return root;

    if (root->left) {
      root->left->next = root->right;
      if (root->next) root->right->next = root->next->left;
      dfs(root->left);
      dfs(root->right);
    }

    return root;
  }

  Node* bfs_optimize(Node* root) {
    if (!root) return root;

    // level leftmost node
    Node* head = root;
    // traverse level
    Node* cur;
    while (head) {
      cur = head;
      while (cur) {
        if (cur->left) {
          cur->left->next = cur->right;
          if (cur->next) cur->right->next = cur->next->left;
        }

        cur = cur->next;
      }
      head = head->left;
    }

    return root;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

vector<int> traverse(Node* root) {
  if (!root) return {};

  vector<int> ans;
  // level leftmost node
  Node* head = root;
  // traverse level
  Node* cur;
  while (head) {
    cur = head;
    while (cur) {
      ans.push_back(cur->val);
      cur = cur->next;
    }
    head = head->left;
  }

  return ans;
}

TEST(PopulatingNextRightPointers, PopulatingNextRightPointers_1) {
  Solution s;
  vector<int> in = {1, 2, 3};
  Tree tree{1, 2, 3, 4, 5, 6, 7};
  vector<int> ans = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(ans, traverse(s.bfs(tree.root)));
}

TEST(PopulatingNextRightPointers, PopulatingNextRightPointers_2) {
  Solution s;
  vector<int> in = {1, 2, 3};
  Tree tree{1, 2, 3, 4, 5, 6, 7};
  vector<int> ans = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(ans, traverse(s.dfs(tree.root)));
}

TEST(PopulatingNextRightPointers, PopulatingNextRightPointers_3) {
  Solution s;
  vector<int> in = {1, 2, 3};
  Tree tree{1, 2, 3, 4, 5, 6, 7};
  vector<int> ans = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(ans, traverse(s.bfs_optimize(tree.root)));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}