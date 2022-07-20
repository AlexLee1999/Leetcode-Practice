/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()) {
            int size = myQueue.size();
            Node* prev;
            for (int i=0; i<size; ++i) {
                Node* current = myQueue.front();
                if(i == 0) {
                    prev = current;
                    
                } else if (i == size-1) {
                    prev->next = current;
                    prev = nullptr;
                } else {
                    prev->next = current;
                    prev = current;
                }
                myQueue.pop();
                if (current->left != nullptr) {
                    myQueue.push(current->left);
                }
                if (current->right != nullptr) {
                    myQueue.push(current->right);
                }
            }
        }
        return root;
    }
};
// Time : O(n)
// Space : O(n)