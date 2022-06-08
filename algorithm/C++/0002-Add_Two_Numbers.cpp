class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = nullptr;
        short carry = 0;
        ListNode* pre = nullptr;
        short value = 0;
        while (l1 != nullptr && l2 != nullptr) {
            value = carry + l1->val + l2->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            if (start == nullptr) {
                start = node;
            }
            if (pre != nullptr) {
                pre->next = node;
            }
            pre = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            value = carry + l1->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            pre->next = node;
            pre = node;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            value = carry + l2->val;
            carry = ((value) / 10);
            ListNode* node = new ListNode(value % 10);
            pre -> next = node;
            pre = node;
            l2 = l2->next;
        }
        if (carry == 1) {
            ListNode* node = new ListNode(1);
            pre -> next = node;
        }
        return start;
    }
};
// Time : O(m + n) 
// Space : O(m + n) new list