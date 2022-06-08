/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A_ptr = headA;
        ListNode *B_ptr = headB;
        while (A_ptr != B_ptr) {
            if (A_ptr == nullptr) {
                A_ptr = headB;
            } else {
                A_ptr = A_ptr->next;
            }
            if (B_ptr == nullptr) {
                B_ptr = headA;
            } else {
                B_ptr = B_ptr->next;
            }
        }
        return A_ptr;
    }
};