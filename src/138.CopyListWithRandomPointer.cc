#include "headers.h"

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node *l1, *l2;

    l1 = head;
    while (l1) {
      l2 = new Node(l1->val);

      l2->next = l1->next;
      l1->next = l2;

      l1 = l2->next;
    }

    Node* newHead = head->next;

    l1 = head;
    while (l1) {
      l2 = l1->next;
      if (l1->random) {
        l2->random = l1->random->next;
      }

      l1 = l1->next->next;
    }

    l1 = head;
    while (l1) {
      l2 = l1->next;
      l1->next = l2->next;
      if (l2->next) {
        l2->next = l2->next->next;
      }

      l1 = l1->next;
    }

    return newHead;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

vector<vector<int>> print(Node*& head) {
  vector<vector<int>> ans;
  Node* p = head;
  while (p) {
    ans.push_back({p->val, p->random ? p->random->val : -1});
    p = p->next;
  }

  return ans;
}

TEST(CopyListWithRandomPointer, CopyListWithRandomPointer_1) {
  Solution s;

  Node* node1 = new Node(7);
  Node* node2 = new Node(13);
  Node* node3 = new Node(11);
  Node* node4 = new Node(10);
  Node* node5 = new Node(1);
  node1->next = node2;
  node1->random = nullptr;
  node2->next = node3;
  node2->random = node1;
  node3->next = node4;
  node3->random = node5;
  node4->next = node5;
  node4->random = node3;
  node5->next = nullptr;
  node5->random = node1;

  Node* res = s.copyRandomList(node1);
  vector<vector<int>> ans = {{7, -1}, {13, 7}, {11, 1}, {10, 11}, {1, 7}};
  EXPECT_EQ(ans, print(res));
}

TEST(CopyListWithRandomPointer, CopyListWithRandomPointer_2) {
  Solution s;

  Node* node1 = new Node(1);
  Node* node2 = new Node(2);

  node1->next = node2;
  node1->random = node2;
  node2->next = nullptr;
  node2->random = node2;

  Node* res = s.copyRandomList(node1);
  vector<vector<int>> ans = {{1, 2}, {2, 2}};
  EXPECT_EQ(ans, print(res));
}

TEST(CopyListWithRandomPointer, CopyListWithRandomPointer_3) {
  Solution s;

  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);

  node1->next = node2;
  node1->random = nullptr;
  node2->next = node3;
  node2->random = node1;
  node3->next = nullptr;
  node3->random = nullptr;

  Node* res = s.copyRandomList(node1);
  vector<vector<int>> ans = {{1, -1}, {2, 1}, {3, -1}};
  EXPECT_EQ(ans, print(res));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}