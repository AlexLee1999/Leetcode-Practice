/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> mySet;
        while (p != nullptr && q != nullptr) {
            if (mySet.count(p) != 0) {
                return p;
            }
            mySet.insert(p);
            if (mySet.count(q) != 0) {
                return q;
            }
            mySet.insert(q);
            p = p->parent;
            q = q->parent;
        }
        while (p != nullptr) {
            if (mySet.count(p) != 0) {
                return p;
            }
            mySet.insert(p);
            p = p->parent;
        }
        while (q != nullptr) {
            if (mySet.count(q) != 0) {
                return q;
            }
            mySet.insert(q);
            q = q->parent;
        }
        return nullptr;
    }
};
// Time : O(n)
// Space : O(n)