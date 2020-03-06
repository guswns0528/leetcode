#include <tuple>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    tuple<ListNode*, ListNode*> reverse(ListNode* head) {
        if (head->next == nullptr) {
            return {head, head};
        }

        auto [h, t] = reverse(head->next);
        t->next = head;
        head->next = nullptr;
        return {h, head};
    }

    tuple<ListNode*, bool> split(ListNode* head, ListNode* prev, int k) {
        if (k == 0) {
            prev->next = nullptr;
            return {head, true};
        }

        if (head == nullptr)
            return {nullptr, false};

        return split(head->next, head, k - 1);
    }

    int count(ListNode* head, int acc) {
        if (head == nullptr) {
            return acc;
        }

        return count(head->next, acc + 1);
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto [next, success] = split(head, nullptr, k);
        if (not success)
            return head;
        auto [h, t] = reverse(head);
        t->next = reverseKGroup(next, k);
        return h;
    }
};

int main(void) {

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node5;

    Solution s;
    auto head = s.reverseKGroup(&node1, 2);

    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';

    return 0;
}
