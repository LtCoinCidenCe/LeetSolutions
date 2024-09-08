#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *result = new ListNode(0);
    ListNode *build = result;
    ListNode *ptr = head;
    while (ptr->next) {
      ptr = ptr->next;
      if (build->next == nullptr) {
        // ok to merge
        if (ptr->val == 0) {
          build->next = new ListNode();
        }
        else {
          build->val += ptr->val;
        }
      }
      else {
        build = build->next;
        build->val = ptr->val;
      }
    }
    delete build->next;
    build->next = nullptr;
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;

  return 0;
}