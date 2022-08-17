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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        while (head != nullptr) {
            if (head->val != val) {
                ptr->next = head;
                ListNode* next = head->next;
                head->next = nullptr;
                head = next;
                ptr = ptr->next;
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }
};
// Time : O(n)
// Space : O(1)