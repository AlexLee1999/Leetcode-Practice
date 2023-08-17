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
    Solution(ListNode* head) {
        listHead = head;
        ptr = head;
        size = 0;
        while (head != nullptr) {
            head = head->next;
            size ++;
        }
    }
    
    int getRandom() {
        int ran = rand() % size;
        for (int i=0; i<ran; ++i) {
            ptr = ptr->next;
            if (ptr == nullptr) {
                ptr = listHead;
            }
        }
        return ptr->val;

    }
private:
    ListNode* listHead;
    ListNode* ptr;
    int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */