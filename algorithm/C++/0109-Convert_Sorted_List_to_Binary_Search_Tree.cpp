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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return recursive(head);
    }
    
    TreeNode* recursive(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* mid = getMid(head);
        TreeNode* new_node = new TreeNode(mid->val);
        if (mid == head) {
            return new_node;
        }
        ListNode* right_head = mid->next;
        mid->next = nullptr;
        new_node->left = recursive(head);
        new_node->right = recursive(right_head);
        return new_node;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
        }
        return slow;        
    }
};
// Time : O(nlogn)
// Space : O(logn)