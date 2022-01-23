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
        while (!myQueue.empty()) {
            int size = myQueue.size();
            Node* prev = nullptr;
            for (int i=0; i<size; ++i) {
                Node* front = myQueue.front();
                myQueue.pop();
                if (i == size-1) {
                    front->next = nullptr;
                }
                if (prev != nullptr) {
                    prev->next = front;
                }
                if (front->left != nullptr) {
                    myQueue.push(front->left);
                    myQueue.push(front->right);
                }
                prev = front;
            }
        }
        return root;
    }
};