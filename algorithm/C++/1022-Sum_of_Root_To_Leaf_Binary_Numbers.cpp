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
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        return result;
    }
    void dfs(TreeNode* root, int current_result, int& result) {
        if (!root->left && !root->right) {
            current_result += root->val;
            result += current_result;
            return;
        }
        current_result += root->val;
        if (root->left) {
            
            dfs(root->left, current_result << 1, result);
        }
        if (root->right) {
            dfs(root->right, current_result << 1, result);
        }
    }
};