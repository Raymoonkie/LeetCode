#include "headers.h"

class Solution {
 public:
  // ListNode* reverseList(ListNode* head) {
  //   ListNode* before = nullptr;
  //   ListNode* cur = head;
  //   while (cur != nullptr) {
  //     ListNode* next = cur->next;
  //     cur->next = before;

  //     before = cur;
  //     cur = next;
  //   }

  //   return before;
  // }

  ListNode* reverseList(ListNode* head) { return reverseList(nullptr, head); }

  ListNode* reverseList(ListNode* node, ListNode* nextNode) {
    if (nextNode == nullptr) {
      return node;
    }

    ListNode* tmp = nextNode->next;
    nextNode->next = node;

    return reverseList(nextNode, tmp);
  }
};

TEST(ReverseLinkedList, ReverseLinkedList_1) {
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

  EXPECT_EQ(list_to_string(s.reverseList(node1)), "5->4->3->2->1");
}

TEST(ReverseLinkedList, ReverseLinkedList_2) {
  Solution s;

  EXPECT_EQ(list_to_string(s.reverseList(nullptr)), "");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}