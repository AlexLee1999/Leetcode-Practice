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
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            size++;
            ptr = ptr->next;
        }
        vector<int> table(size, 0);
        ptr = head;
        int count = 0;
        int max_sum = 0;
        while (ptr != nullptr) {
            if (count <= (size / 2 - 1)) {
                table[count] = ptr->val;
                ptr = ptr->next;
                count ++;
            } else {
                max_sum = max(max_sum , ptr->val + table[size - 1 - count]);
                ptr = ptr->next;
                count ++;
            }
        }
        return max_sum;
    }
};
// Time : O(n)
// Space : O(n)