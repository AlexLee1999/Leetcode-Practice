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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
        
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* old_dummy = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val > right->val) {
                dummy->next = right;
                right = right->next;
                dummy = dummy->next;
            } else {
                dummy->next = left;
                left = left->next;
                dummy = dummy->next;
            }
        }
        if (left != nullptr) {
            dummy->next = left;
        } else {
            dummy->next = right;
        }
        return old_dummy->next;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next !=nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        return slow;
    }
};
// Time : O(nlogn)
// Space : O(n)
// Merge sort