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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* pre = nullptr;
        while(true){
            if(pre != nullptr){
                pre->next = right;
            }
            left->next = right->next;
            right->next = left;
            if(head == left){
                head = right;
            }
            pre = left;
            if(left->next != nullptr && left->next->next != nullptr){
                right = right->next->next->next;
                left = left->next;
            }
            else{
                break;
            }
        }
        return head;
    }
};
// Time : O(N)
// Space : O(1)