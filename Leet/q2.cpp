struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int plus = 0, add = 1;
        ListNode* emptyfirst = new ListNode(0, new ListNode()), * previous = emptyfirst;
        bool onedone = l1 == nullptr;
        bool twodone = l2 == nullptr;

        while (true)
        {
            // core
            add = (onedone ? 0 : l1->val) + (twodone ? 0 : l2->val) + plus;
            if (add == 0 && onedone && twodone)
            {
                break;
            }
            // something is here

            plus = add / 10;
            previous->next = new ListNode(add % 10);
            previous = previous->next;

            onedone = l1->next == nullptr;
            twodone = l2->next == nullptr;
            if (!onedone)
            {
                l1 = l1->next;
            }
            if (!twodone)
            {
                l2 = l2->next;
            }

        }
        return emptyfirst->next;
    }
};

int q2()
{
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution solution;
    auto first = solution.addTwoNumbers(l1, l2);
    return 0;
}
