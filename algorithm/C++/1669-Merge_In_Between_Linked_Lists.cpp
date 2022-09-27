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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* nxt = list1;
        for (int i=0; i<a-1; ++i) {
            prev = prev->next;
        }
        for (int j=0; j<=b; ++j) {
            nxt = nxt->next;
        }
        prev->next = list2;
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = nxt;
        return list1;
    }
};
// Time : O(n + m)
// Space : O(1)