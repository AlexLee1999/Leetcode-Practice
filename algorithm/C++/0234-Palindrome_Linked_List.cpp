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
        
        // Cut the first half
        prev_slow->next = nullptr;
        // Reverse the second half of the linked list
        ListNode* current_ptr = slow;
        ListNode* prev_ptr = nullptr;
        ListNode* temp = nullptr;
        while (current_ptr != nullptr) {
            temp = current_ptr->next;
            current_ptr->next = prev_ptr;
            prev_ptr = current_ptr;
            current_ptr = temp;
        }
        while (prev_ptr != nullptr && head !=nullptr) {
            if (prev_ptr->val != head->val) {
                return false;
            }
            prev_ptr = prev_ptr->next;
            head = head->next;
        }
        // [1, 0, 1]
        // prev_ptr = [1, 0]
        // head = [1]
        // if prev_ptr != nullptr, the num of the list is odd
        // However, the fast-slow ptr ensure that there is only one node left in prev_ptr
        // Therefore return true
        return true;
    }
};