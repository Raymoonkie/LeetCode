#include "headers.h"

class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  vector<NestedInteger> &getList() const;
};

class NestedIterator {
 private:
  stack<vector<NestedInteger>::iterator> _start, _end;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    _start.push(begin(nestedList));
    _end.push(end(nestedList));
  }

  int next() { return _start.top()++->getInteger(); }

  bool hasNext() {
    while (size(_start)) {
      if (_start.top() == _end.top()) {
        _start.pop();
        _end.pop();
        continue;
      }

      auto top = _start.top();
      if (top->isInteger()) break;

      _start.top()++;
      auto &list = top->getList();
      _start.push(begin(list));
      _end.push(end(list));
    }

    return size(_start);
  }
};

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}