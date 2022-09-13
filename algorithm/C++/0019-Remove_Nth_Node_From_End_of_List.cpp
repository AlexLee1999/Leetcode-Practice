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
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = dummy;

        for (int i=1; i<=n + 1; ++i){
            right = right->next;
        }
        while (right != nullptr){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};
// Time : O(L) L is the length of the linked list
// Space : O(1)
