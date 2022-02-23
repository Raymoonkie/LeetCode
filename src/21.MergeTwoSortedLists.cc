#include "headers.h"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;

    while (p && q) {
      if (p->val < q->val) {
        cur->next = p;
        p = p->next;
      } else {
        cur->next = q;
        q = q->next;
      }
      cur = cur->next;
    }

    cur->next = p ? p : q;

    return head->next;
  }
};

TEST(MergeTwoSortedLists, MergeTwoSortedLists_1) {
  Solution s;
  ListNode* list1 = new ListNode(1);
  ListNode* list2 = new ListNode(1);
  ListNode* list3 = new ListNode(3);
  EXPECT_EQ(list_to_string(s.mergeTwoLists(list1, list2)), "1->1");
  EXPECT_EQ(list_to_string(s.mergeTwoLists(nullptr, nullptr)), "");
  EXPECT_EQ(list_to_string(s.mergeTwoLists(nullptr, list3)), "3");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}