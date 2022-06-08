/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> mySet;
        while (headA != nullptr || headB != nullptr) {
            if (headA != nullptr) {
                if (mySet.count(headA) == 0) {
                    mySet.insert(headA);
                } else {
                    return headA;
                }
                headA = headA->next;
            }
            if (headB != nullptr) {
                if (mySet.count(headB) == 0) {
                    mySet.insert(headB);
                } else {
                    return headB;
                }
                headB = headB->next;
            }
        }
        return nullptr;
    }
};