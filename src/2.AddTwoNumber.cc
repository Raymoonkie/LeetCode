#include "headers.h"

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
    int step = 0;

    ListNode* ans = p;
    ListNode* head = p;
    while (p || q) {
      if (p) {
        step += p->val;
        p = p->next;
      }

      if (q) {
        step += q->val;
        q = q->next;
      }

      ans->next = p ? p : q;
      ans->val = step % 10;
      step /= 10;

      ans = ans->next ? ans->next : ans;
    }

    if (step == 1) {
      ans->next = new ListNode(1);
    }

    return head;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(AddTwoNumber, AddTwoNumber_1) {
  Solution s;
  List list1{2, 4, 3};
  List list2{5, 6, 4};
  ListNode* ans = s.addTwoNumbers(list1.head, list2.head);
  EXPECT_EQ(list_to_string(ans), "7->0->8");
}

TEST(AddTwoNumber, AddTwoNumber_2) {
  Solution s;
  List list1{0};
  List list2{0};
  ListNode* ans = s.addTwoNumbers(list1.head, list2.head);
  EXPECT_EQ(list_to_string(ans), "0");
}

TEST(AddTwoNumber, AddTwoNumber_3) {
  Solution s;
  List list1{9, 9, 9, 9, 9, 9, 9};
  List list2{9, 9, 9, 9};
  ListNode* ans = s.addTwoNumbers(list1.head, list2.head);
  EXPECT_EQ(list_to_string(ans), "8->9->9->9->0->0->0->1");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}