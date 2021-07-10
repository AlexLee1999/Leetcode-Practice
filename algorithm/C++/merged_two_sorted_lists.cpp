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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2){
            return nullptr;
        }
        ListNode* head = new ListNode();
        ListNode* pre = head;
        while(l1 != nullptr || l2 != nullptr){
            ListNode* temp;
            if(l1 == nullptr || (l2 != nullptr && (l1 -> val >= l2-> val))){
                temp = l2;
                l2 = l2->next;
            }
            else{
                temp = l1;
                l1 = l1->next;
            }
            pre->next = temp;
            pre = temp;
        }
        return head->next;
    }
};
