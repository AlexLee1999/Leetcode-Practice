/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    Node* dfs(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        while (head->child == nullptr && head->next != nullptr) {
            head = head->next;
        }
        if (head->child == nullptr) {
            return head;
        }
        Node* child_tail = dfs(head->child);
        Node* next_tail = dfs(head->next);
        Node* tmp = head->next;
        head->next = head->child;
        head->next->prev = head;
        head->child = nullptr;
        if (tmp != nullptr) {
            child_tail->next = tmp;
            child_tail->next->prev = child_tail;
        }
        if (next_tail == nullptr) {
            return child_tail;
        }
        return next_tail;
    }
};
// Time : O(n)
// Space : O(n)