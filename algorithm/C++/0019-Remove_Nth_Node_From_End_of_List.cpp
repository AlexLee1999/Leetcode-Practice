/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;

        for (int i = 0; i < n; ++i) {
            right = right->next;
        }
        if (right == nullptr) {
            return head->next;
        }
        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head;
    }
};
// Time : O(L) L is the length of the linked list
// Space : O(1)
