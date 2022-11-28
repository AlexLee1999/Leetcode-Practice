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
    int maxDepth(TreeNode* root) {
        return check_tree(root);
    }
    int check_tree(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        return max(check_tree(node->left), check_tree(node->right)) + 1;
    }
};
// Time : O(n)
// Space : O(H)
