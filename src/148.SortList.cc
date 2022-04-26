#include "headers.h"

class Solution {
 public:
  ListNode* sortList(ListNode* head) { return merge_sort_recurse(head); }

  ListNode* quick_sort(ListNode* head, ListNode* tail) {
    if (head != tail) {
      ListNode* smaller;
      ListNode** smaller_next = &smaller;

      ListNode** p = &head->next;
      while (*p != tail) {
        if ((*p)->val < head->val) {
          *smaller_next = *p;
          smaller_next = &((*smaller_next)->next);
          *p = (*p)->next;
        } else {
          p = &((*p)->next);
        }
      }

      *smaller_next = head;
      head->next = quick_sort(head->next, tail);
      head = quick_sort(smaller, head);
    }

    return head;
  }

  ListNode* merge_sort_recurse(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *fast = head, *slow = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = nullptr;

    ListNode* l1 = merge_sort_recurse(head);
    ListNode* l2 = merge_sort_recurse(slow);

    return merge(l1, l2);
  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode newHead;
    ListNode* p = &newHead;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }

      p = p->next;
    }

    if (l1) p->next = l1;
    if (l2) p->next = l2;

    return newHead.next;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(SortList, SortList_1) {
  Solution s;
  List in{-1, 5, 3, 4, 0};
  List ans{-1, 0, 3, 4, 5};
  EXPECT_EQ(true, is_same_list(s.quick_sort(in.head, nullptr), ans.head));

  List in2{-1, 5, 3, 4, 0};
  EXPECT_EQ(true, is_same_list(s.merge_sort_recurse(in2.head), ans.head));
}

TEST(SortList, SortList_2) {
  Solution s;
  EXPECT_EQ(true, is_same_list(s.quick_sort(nullptr, nullptr), nullptr));
  EXPECT_EQ(true, is_same_list(s.merge_sort_recurse(nullptr), nullptr));
}

TEST(SortList, SortList_3) {
  Solution s;
  List in{4, 2, 1, 3};
  List ans{1, 2, 3, 4};
  EXPECT_EQ(true, is_same_list(s.quick_sort(in.head, nullptr), ans.head));

  List in2{4, 2, 1, 3};
  EXPECT_EQ(true, is_same_list(s.merge_sort_recurse(in2.head), ans.head));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}