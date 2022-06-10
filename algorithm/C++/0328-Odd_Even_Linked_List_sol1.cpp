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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = head;
        ListNode* prev = head;
        head = head->next;
        vector<ListNode*> table;
        int count = 1;
        while (head != nullptr) {
            if (count & 1 == 1) {
                prev->next = head->next;
                ListNode* old_head = head;
                head->next = nullptr;
                table.push_back(head);
                head = prev->next;
                prev = old_head;
            } else {
                prev = head;
                head = head->next;
            }
            count ++;
        }
        head = dummy;
        while (head->next != nullptr) {
            head = head->next;
        }
        for (int i=0; i<table.size(); ++i) {
            head->next = table[i];
            head = head->next;
        }
        return dummy;
    }
};
// Time : O(n)
// Space : O(n)