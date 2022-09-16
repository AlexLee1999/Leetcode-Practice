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
    Node* inorderSuccessor(Node* node) {
        if (node-> right != nullptr) {
            Node* ptr = node;
            ptr = ptr->right;
            while (ptr->left != nullptr) {
                ptr = ptr->left;
            }
            return ptr;
        } else if (node->parent != nullptr && node == node->parent->left){
            return node->parent;
        } else if (node->parent != nullptr && node == node->parent->right) {
            Node * ptr = node;
            while (ptr->parent != nullptr && ptr == ptr->parent->right) {
                ptr = ptr->parent;
            }
            return ptr->parent;
        }
        return nullptr;
    }
};
// Time : O(H)
// Space : O(1)