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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = head;
        while (head != nullptr && head->next != nullptr) {
            ListNode* old_head = head;
            while (head->next != nullptr && (head->val == head->next->val)) {
                head = head->next;
            }
            old_head->next = head->next;
            head = head->next;
        }
        return dummy;
    }
};
// Time : O(n)
// Space : O(1)