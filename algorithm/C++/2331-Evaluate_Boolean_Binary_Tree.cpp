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
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
    bool dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        return root->val == 2 ? left || right : left && right;
    }
};
// Time : O(n)
// Space : O(1)