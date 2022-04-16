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
    TreeNode* convertBST(TreeNode* root) {
        int current = 0;
        dfs(root, current);
        return root;
    }
    void dfs(TreeNode* root, int& current) {
        if (root == nullptr) {
            return;
        }
        if (root->right != nullptr) {
            dfs(root->right, current);
        }
        int val = root->val;
        root->val += current;
        current += val;
        if (root->left != nullptr) {
            dfs(root->left, current);
        }
    }
};