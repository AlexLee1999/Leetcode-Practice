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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        int count = 0;
        ListNode* parthead = head;
        vector<ListNode*> list_arr;
        while (head != nullptr) {
            count ++;
            prev = head;
            head = head->next;
            if (count % k == 0) {
                prev->next = nullptr;
                list_arr.push_back(parthead);
                parthead = head;
            }
        }
        bool listLeft = false;
        if (parthead != nullptr) {
            list_arr.push_back(parthead);
            listLeft = true;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* old_dummy = dummy;
        for (int i=0; i<list_arr.size(); ++i) {
            if (!listLeft || i != list_arr.size() - 1){
                list_arr[i] = reverseList(list_arr[i]);
            }
            dummy->next = list_arr[i];
            while(dummy->next != nullptr) {
                dummy = dummy->next;
            }
        }
        return old_dummy->next;
    }
    ListNode* reverseList(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        ListNode* new_node = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return new_node;
    }
};
// Time : O(n)
// Space : O(k)