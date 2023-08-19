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
    ListNode* doubleIt(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
          arr.push_back(head->val);
          head = head->next;
        }
        int carry = 0;
        for (int i=arr.size() - 1; i >= 0; --i) {
          int num = arr[i] * 2;
          arr[i] = num % 10 + carry;
          carry = num / 10;
        }
        if (carry > 0) {
          arr.insert(arr.begin(), 1);
        }
        ListNode* result = new ListNode();
        ListNode* ans = result;
        for (int i=0; i<arr.size(); ++i) {
          result->next = new ListNode(arr[i]);
          result = result->next;
        }
        return ans->next;
    }
};