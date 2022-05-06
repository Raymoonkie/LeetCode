#include "headers.h"

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;

    ListNode* p = head;

    ListNode* evenHead = new ListNode(-1);
    ListNode* q = evenHead;

    while (p->next) {
      q->next = p->next;
      q = q->next;

      p->next = q->next;
      q->next = nullptr;
      if (p->next) {
        p = p->next;
      }
    }

    p->next = evenHead->next;

    // delete evenHead;

    return head;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(OddEvenLinkedList, OddEvenLinkedList_1) {
  Solution s;
  List l1{1, 2, 3, 4, 5};
  List l2{1, 3, 5, 2, 4};
  EXPECT_EQ(is_same_list(s.oddEvenList(l1.head), l2.head), true);
}

TEST(OddEvenLinkedList, OddEvenLinkedList_2) {
  Solution s;
  List l1{2, 1, 3, 5, 6, 4, 7};
  List l2{2, 3, 6, 7, 1, 5, 4};
  EXPECT_EQ(is_same_list(s.oddEvenList(l1.head), l2.head), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}