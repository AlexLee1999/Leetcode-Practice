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
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* old_dummy = dummy;
        while (head != nullptr) {
            dummy = old_dummy->next;
            ListNode* prev = old_dummy;
            while (dummy != nullptr && dummy->val < head->val) {
                prev = dummy;
                dummy = dummy->next;
            }
            ListNode* new_head = head->next;
            head->next = prev->next;
            prev->next = head;
            head = new_head;
        } 
        return old_dummy->next;
    }
};
// Time : O(n^2)
// Space : O(1)
// Insertion Sort (TLE)