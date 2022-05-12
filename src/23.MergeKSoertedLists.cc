#include "headers.h"

struct compare {
  bool operator()(const ListNode* lhs, const ListNode* rhs) const {
    return (lhs->val > rhs->val);
  }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) { return s2(lists); }

  ListNode* s1(vector<ListNode*>& lists) {
    ListNode* newHead = new ListNode(-1);

    ListNode* p = newHead;
    ListNode* minNode = nullptr;
    int min = INT_MAX;
    while (true) {
      for (auto head : lists) {
        if (head && head->val < min) {
          minNode = head;
          head = head->next;
          break;
        }
      }

      if (!minNode) break;
      p->next = minNode;
      p = p->next;

      // reset for next
      minNode = nullptr;
      min = INT_MAX;
    }

    return newHead->next;
  }

  ListNode* s2(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> q;

    for (auto list : lists) {
      if (list) {
        q.push(list);
      }
    }

    ListNode* newHead = new ListNode(-1);
    ListNode* p = newHead;
    while (!q.empty()) {
      auto head = q.top();
      q.pop();

      p->next = head;
      p = p->next;

      head = head->next;
      if (head) {
        q.push(head);
      }
    }

    return newHead->next;
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

TEST(MergeKSoertedLists, MergeKSoertedLists_1) {
  Solution s;
  List list1{1, 4, 5};
  List list2{1, 3, 4};
  List list3{2, 6};

  List list4{1, 1, 2, 3, 4, 4, 5, 6};
  vector<ListNode*> in = {list1.head, list2.head, list3.head};
  EXPECT_EQ(true, is_same_list(s.mergeKLists(in), list4.head));
}

TEST(MergeKSoertedLists, MergeKSoertedLists_2) {
  Solution s;

  List list4{};
  vector<ListNode*> in = {};
  EXPECT_EQ(true, is_same_list(s.mergeKLists(in), list4.head));
}

TEST(MergeKSoertedLists, MergeKSoertedLists_3) {
  Solution s;

  List list4{};
  vector<ListNode*> in = {list4.head};
  EXPECT_EQ(true, is_same_list(s.mergeKLists(in), list4.head));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}