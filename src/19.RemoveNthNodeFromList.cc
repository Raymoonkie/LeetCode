#include "headers.h"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) {
      return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while (n > 0) {
      fast = fast->next;
      n--;
    }

    // remove first
    if (fast == nullptr) {
      return head->next;
    }

    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    ListNode* deleted = slow->next;
    slow->next = deleted->next;

    return head;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(RemoveNthNodeFromList, RemoveNthNodeFromList_1) {
  Solution s;
  List in{1, 2, 3, 4, 5};
  List out{1, 2, 3, 5};

  ListNode* ans = s.removeNthFromEnd(in.head, 2);
  EXPECT_EQ(list_to_string(out.head), list_to_string(ans));
}

TEST(RemoveNthNodeFromList, RemoveNthNodeFromList_2) {
  Solution s;
  List in{1, 2};
  List out{1};

  ListNode* ans = s.removeNthFromEnd(in.head, 1);
  EXPECT_EQ(list_to_string(out.head), list_to_string(ans));
}

TEST(RemoveNthNodeFromList, RemoveNthNodeFromList_3) {
  Solution s;
  List in{1, 2};
  List out{2};

  ListNode* ans = s.removeNthFromEnd(in.head, 2);
  EXPECT_EQ(list_to_string(out.head), list_to_string(ans));
}

TEST(RemoveNthNodeFromList, RemoveNthNodeFromList_4) {
  Solution s;
  List in{1};
  List out{};

  ListNode* ans = s.removeNthFromEnd(in.head, 2);
  EXPECT_EQ(list_to_string(out.head), list_to_string(ans));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}