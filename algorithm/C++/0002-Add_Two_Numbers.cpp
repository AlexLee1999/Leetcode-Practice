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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        ListNode* ptr = dummy;
        int value = 0;
        while(l1 != nullptr && l2 != nullptr){
            value = carry + l1->val + l2->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            ptr->next = node;
            ptr = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            value = carry + l1->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            ptr->next = node;
            ptr = node;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            value = carry + l2->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            ptr -> next = node;
            ptr = node;
            l2 = l2->next;
        }
        if(carry == 1){
            ListNode* node = new ListNode(1);
            ptr->next = node;
        }
        return dummy->next;
    }
};
// Time : O(m + n) 
// Space : O(m + n) new list