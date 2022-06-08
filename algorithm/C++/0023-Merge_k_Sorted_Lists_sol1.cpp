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
    void merge(vector<ListNode*>& lists, int left, int right){
        ListNode* l1 = lists[left];
        ListNode* l2 = lists[right];
        if (!l1 && !l2) {
            lists[left] = nullptr;
            return;
        }
        ListNode* head = new ListNode();
        ListNode* pre = head;
        while (l1 != nullptr || l2 != nullptr) {
            ListNode* temp;
            if (l1 == nullptr || (l2 != nullptr && (l1 -> val >= l2-> val))) {
                temp = l2;
                l2 = l2->next;
            }
            else {
                temp = l1;
                l1 = l1->next;
            }
            pre->next = temp;
            pre = temp;
        }
        lists[left] = head->next;
        return;

    }
    void partition(vector<ListNode*>& lists, int left, int right){
        if (left < right) {
        int mid = (left + right) / 2;
        partition(lists, left, mid);
        partition(lists, mid + 1, right);
        merge(lists, left, mid + 1);
        }

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        partition(lists, 0, lists.size() - 1);
        return lists[0];
    }
};

// Time : O(Nlogk) N is the total number of nodes, k is the size of lists
// Space : O(1)
