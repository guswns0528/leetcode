#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unique_ptr<ListNode> head(new ListNode(0));
        ListNode* last = head.get();
        while (true) {
            auto minimum = 0;
            auto min_index = -1;

            for (auto i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr)
                    continue;

                if (min_index == -1 or lists[i]->val < minimum) {
                    minimum = lists[i]->val;
                    min_index = i;
                }
            }

            if (min_index == -1)
                break;

            last->next = lists[min_index];
            lists[min_index] = lists[min_index]->next;
            last = last->next;
        }

        return head->next;
    }
};

int main(void) {
    Solution s;

    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(5);
    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    ListNode node7(2);
    ListNode node8(6);

    node1.next = &node2;
    node2.next = &node3;

    node4.next = &node5;
    node5.next = &node6;

    node7.next = &node8;

    vector<ListNode*> input{&node1, &node4, &node7};

    auto result = s.mergeKLists(input);
    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';
    return 0;
}
