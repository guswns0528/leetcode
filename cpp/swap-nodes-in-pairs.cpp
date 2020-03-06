#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;

        auto first = head;
        auto second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};

int main(void) {
    return 0;
}
