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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        //return the new head
        ListNode* newHead = reverseList(head->next);
        //reverse the pointer (head=> head->next)=>(head->next=>head)
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
