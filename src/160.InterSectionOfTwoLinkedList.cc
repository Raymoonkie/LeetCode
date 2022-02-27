#include "headers.h"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
      a = a == nullptr ? headB: a->next;
      b = b == nullptr ? headA: b->next;
    }

    return a;
  }
};

TEST(InterSectionOfTwoLinkedList, InterSectionOfTwoLinkedList_1) {
  Solution s;
  ListNode *headA = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);
  headA->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  ListNode *headB = new ListNode(-1);
  ListNode *node5 = new ListNode(-2);
  headB->next = node5;
  node5->next = node2;

  EXPECT_EQ(s.getIntersectionNode(headA, headB), node2);
}

TEST(InterSectionOfTwoLinkedList, InterSectionOfTwoLinkedList_2) {
  Solution s;
  ListNode *headA = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);
  headA->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  ListNode *headB = new ListNode(-1);
  ListNode *node5 = new ListNode(-2);
  headB->next = node5;

  EXPECT_EQ(s.getIntersectionNode(headA, headB), nullptr);
}

TEST(InterSectionOfTwoLinkedList, InterSectionOfTwoLinkedList_3) {
  Solution s;
  ListNode *headA = new ListNode(1);


  EXPECT_EQ(s.getIntersectionNode(headA, headA), headA);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}