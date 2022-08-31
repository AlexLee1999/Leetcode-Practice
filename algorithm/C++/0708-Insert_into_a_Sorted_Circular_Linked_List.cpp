/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* tmp = new Node(insertVal);
            tmp->next = tmp;
            return tmp;
        }
        Node* ptr = head;
        while (ptr->next != head) {
            if (ptr->next->val >= insertVal && ptr->val <= insertVal) { // 1-2-4 insert 3
                break;
            } else if (ptr->val > ptr->next->val) {
                if (ptr->next->val >= insertVal && ptr->val >= insertVal) { //1-2-3 insert 0
                    break;
                }
                if (ptr->next->val <= insertVal && ptr->val <= insertVal) { // 1-2-3 insert 4
                    break;
                }
            }
            ptr = ptr->next;
        }
        Node* tmp = new Node(insertVal); // if all values are same, random choose a node to insert
        tmp->next = ptr->next;
        ptr->next = tmp;
        return head;
    }
};
// Time : O(n)
// Space : O(1)