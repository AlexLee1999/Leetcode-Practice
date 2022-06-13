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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left_prev = dummy;
        for (int i=1; i<=left-1; ++i) {
            left_prev = left_prev->next;
        }
        ListNode* left_ptr = left_prev->next;
        ListNode* right_prev = dummy;
        for (int i=1; i<=right; ++i) {
            right_prev = right_prev->next;
        }
        ListNode* right_part = right_prev->next;
        // Cut and reverse the list
        right_prev->next = nullptr;
        left_prev->next = reverse(left_ptr);
        ListNode* ptr = dummy;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = right_part;
        return dummy->next;
        
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