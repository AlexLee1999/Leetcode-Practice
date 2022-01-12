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
    struct compare
    {
        bool operator()(ListNode* &a,ListNode* &b)
        {
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* head = new ListNode();
        ListNode* temp = head;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                heap.push(lists[i]);
            }
        }
        while (!heap.empty()) {
            ListNode* topElement = heap.top();
            heap.pop();
            if (topElement->next != nullptr) {
                heap.push(topElement->next);
            }
            temp->next = topElement;
            temp = topElement;
        }
        return head->next;
    }
};
