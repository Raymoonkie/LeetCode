#include "headers.h"

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    if (head == head->next) {
      return true;
    }

    ListNode* p = head;
    ListNode* q = head;

    while (q != nullptr && q->next != nullptr) {
      p = p->next;
      q = q->next->next;
      if (p == q) {
        return true;
      }
    }

    return false;
  }
};

TEST(LinkedListCycle, LinkedListCycle_1) {
  Solution s;
  ListNode* head = new ListNode(3);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node1;
  EXPECT_EQ(s.hasCycle(head), true);
}

TEST(LinkedListCycle, LinkedListCycle_2) {
  Solution s;
  ListNode* head = new ListNode(3);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  EXPECT_EQ(s.hasCycle(head), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}