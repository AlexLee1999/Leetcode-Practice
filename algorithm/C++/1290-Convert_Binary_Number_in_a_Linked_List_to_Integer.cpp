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
    int getDecimalValue(ListNode* head) {
        int val = head->val;
        head = head->next;
        while (head != nullptr) {
            val <<= 1;
            val += head->val;
            head = head->next;
        }
        return val;
    }
};
// Time : O(n)
// Space : O(1)