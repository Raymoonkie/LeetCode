#include "headers.h"

class Solution {
 public:
  void deleteNode(ListNode* node) { *node = *node->next; }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(DeleteNodeInLinkedList, DeleteNodeInLinkedList_1) {
  Solution s;
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  s.deleteNode(node3);
  EXPECT_EQ(list_to_string(node1), "1->2->4->5");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}