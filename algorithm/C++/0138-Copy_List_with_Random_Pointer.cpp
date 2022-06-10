/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> myMap;
        Node* old_head = head;
        Node* prev = nullptr;
        while (head != nullptr) {
            myMap[head] = new Node(head->val);
            if (prev != nullptr) {
                prev->next = myMap[head];
            }
            prev = myMap[head];
            head = head->next;
        }
        head = old_head;
        while (head != nullptr) {
            if (head->random != nullptr) {
                myMap[head]->random = myMap[head->random];
            }
            head = head->next;
        }
        return myMap[old_head];
    }
};
// Time : O(n)
// Space : O(n)