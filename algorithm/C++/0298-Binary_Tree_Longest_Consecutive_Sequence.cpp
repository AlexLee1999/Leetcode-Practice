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
    int longestConsecutive(TreeNode* root) {
        int max_len = INT_MIN;
        dfs(root, max_len, 1);
        return max_len;
    }
    void dfs(TreeNode* root, int& max_len, int current) {
        
        if (root == nullptr) {
            return;
        }
        max_len = max(max_len, current);
        if (root->left != nullptr) {
            if (root->left->val - root->val == 1) {
                dfs(root->left, max_len, current + 1);
            } else {
                dfs(root->left, max_len, 1);
            }
        }
        if (root->right != nullptr) {
            if (root->right->val - root->val == 1) {
                dfs(root->right, max_len, current + 1);
            } else {
                dfs(root->right, max_len, 1);
            }
        }
    }
};