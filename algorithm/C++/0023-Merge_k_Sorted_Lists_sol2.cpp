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
        bool operator()(ListNode* &a,ListNode* &b) {
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> myHeap;
        for (int i=0; i < lists.size(); ++i){
            if(lists[i] != nullptr){
                myHeap.push(lists[i]);
            }
        }
        
        while (!myHeap.empty()) {
            ListNode* top_element = myHeap.top();
            myHeap.pop();
            if (top_element->next != nullptr) {
                myHeap.push(top_element->next);
            }
            ptr->next = top_element;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};691. Stickers to Spell Word
// Time : O(Nlogk) N is the total number of nodes, k is the size of lists
// Space : O(k) At most k nodes in Heap
