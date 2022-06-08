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
        if (head == nullptr || head->next == nullptr) {
            return head; //for last node if odd, or null node if even
        }
        //return the head of swapped node
        ListNode* newHead;
        //the right node is the new nead
        newHead = head -> next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }
};
// Time : O(N)
// Space : O(N)

