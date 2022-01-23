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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev_slow;
        while (fast != nullptr && fast->next != nullptr) {
            prev_slow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* left = head;
        ListNode* right;
        ListNode* current = slow;
        prev_slow->next = nullptr;
        ListNode* temp;
        ListNode* prev = nullptr;
        
        while (current != nullptr) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        right = prev;
        ListNode* dummy = new ListNode(0);
        ListNode* old_dummy = dummy;
        while (left != nullptr && right != nullptr) {
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;
            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }
        if (left!= nullptr) {
            dummy->next = left;
        }
        head = old_dummy->next;
    }
};