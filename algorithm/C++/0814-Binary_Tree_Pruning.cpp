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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};
// Time : O(n)
// Space : O(H)