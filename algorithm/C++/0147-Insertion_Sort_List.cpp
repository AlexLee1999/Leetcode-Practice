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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        
        while (head != nullptr) {
            ListNode* listptr = dummy;
            while (listptr->next != nullptr && head->val > listptr->next->val) {
                listptr = listptr->next;
                
            }
            ListNode* next = head->next;
            head->next = listptr->next;
            listptr->next = head;
            head = next;
        }
        return dummy->next;
        
    }
};