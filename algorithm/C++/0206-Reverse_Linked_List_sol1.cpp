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
        ListNode* pre = nullptr;
        ListNode* nextNode = nullptr;
        while (head != nullptr) {
            nextNode = head->next;
            head->next = pre;
            pre = head;
            head = nextNode;
        }
        return pre;
    }
};
// Time : O(n)
// Space : O(1)