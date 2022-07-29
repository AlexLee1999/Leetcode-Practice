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
    ListNode* plusOne(ListNode* head) {
        ListNode* new_head = reverse(head);
        ListNode* tmp = new_head;
        int carry = (tmp->val + 1) / 10;
        tmp->val = (tmp->val + 1) % 10;
        ListNode* prev = tmp;
        tmp = tmp->next;
        while (carry != 0 && tmp != nullptr) {
            carry = (tmp->val + 1) / 10;
            tmp->val = (tmp->val + 1) % 10;
            prev = tmp;
            tmp = tmp->next;
        }
        if (carry == 1) {
            prev->next = new ListNode(1);
        }
        return reverse(new_head);
        
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* new_node = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_node;
    }
};
// Time : O(n)
// Space : O(n)