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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = head;
        int count = 0;
        while (ptr != nullptr) {
            ptr = ptr->next;
            count ++;
        }
        k = k % count;
        if (k == 0) {
            return head;
        }
        for (int i=0; i<k; ++i) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ptr = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return ptr;
    }
};
// Time : O(n)
// Space : O(1)