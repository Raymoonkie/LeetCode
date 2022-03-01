#include "headers.h"

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;

      ListNode* tmp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = tmp;
    }

    if (fast != nullptr) {
      slow = slow->next;
    }

    while (prev != nullptr && slow != nullptr) {
      if (prev->val != slow->val) {
        return false;
      }

      slow = slow->next;
      prev = prev->next;
    }

    return slow == nullptr && prev == nullptr;
  }
};

static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();

TEST(PalindromeLinkedList, PalindromeLinkedList_1) {
  Solution s;
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(2);
  ListNode* node5 = new ListNode(1);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  bool ans = true;
  EXPECT_EQ(s.isPalindrome(node1), ans);
}

TEST(PalindromeLinkedList, PalindromeLinkedList_2) {
  Solution s;
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(2);
  ListNode* node5 = new ListNode(1);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  bool ans = false;
  EXPECT_EQ(s.isPalindrome(node1), ans);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}