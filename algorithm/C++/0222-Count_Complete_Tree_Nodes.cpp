/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int left = left_height(root);
        int right = right_height(root);
        if (left == right) {
            return (1<<left) -1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int left_height(TreeNode* root) {
        int height = 0;
        while(root) {
            height ++;
            root = root->left;
        }
        return height;
    }
    int right_height(TreeNode* root) {
        int height = 0;
        while(root) {
            height ++;
            root = root->right;
        }
        return height;
    }
};