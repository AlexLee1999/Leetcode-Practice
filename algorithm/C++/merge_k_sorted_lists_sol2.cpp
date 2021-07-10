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
        if(lists.size()==0){
            return nullptr;
        }
        ListNode* head = new ListNode();
        ListNode* temp = head;
        priority_queue<ListNode*,vector<ListNode*>,compare> heap;
        for(int i=0; i< lists.size(); ++i){
            if(lists[i] != nullptr){
                heap.push(lists[i]);
            }
        }
        while(!heap.empty()){
            ListNode* top_element = heap.top();
            heap.pop();
            if(top_element->next != nullptr){
                heap.push(top_element->next);
            }
            temp->next = top_element;
            temp = top_element;
        }
        return head->next;
    }
};
