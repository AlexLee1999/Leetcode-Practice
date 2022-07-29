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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev_slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev_slow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev_slow->next = nullptr;
        
        
        // Reverse the second half of the linked list
        ListNode* current_ptr = slow;
        ListNode* prev_ptr = nullptr;
        while (current_ptr != nullptr) {
            ListNode* temp = current_ptr->next;
            current_ptr->next = prev_ptr;
            prev_ptr = current_ptr;
            current_ptr = temp;
        }
        
        // Compare the first half and the second half
        ListNode* first_half_ptr = head;
        ListNode* second_half_ptr = prev_ptr;
        
        while (first_half_ptr != nullptr && second_half_ptr !=nullptr) {
            if (first_half_ptr->val != second_half_ptr->val) {
                return false;
            }
            first_half_ptr = first_half_ptr->next;
            second_half_ptr = second_half_ptr->next;
        }
        // Consider the case : [1, 0, 1]
        // second_half_ptr = [1, 0]
        // head = [1]
        // if second_half_ptr != nullptr, the num of the list is odd
        // However, the fast-slow ptr ensure that there is only one node left in second_half_ptr
        // Therefore return true
        return true;
    }
};
// Time : O(n)
// Space : O(1)