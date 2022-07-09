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
        if (node->right != nullptr) {
            return minNode(node->right);
        }
        if (node->parent == nullptr) {
            return nullptr;
        }
        if (node->parent->left == node) {
            return node->parent;
        }
        while (node->parent != nullptr && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
    Node* minNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};
// Time : O(H)
// Space : O(1)