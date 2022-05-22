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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, to_string(root->val), ans);
        return ans;
    }
    void dfs(TreeNode* root, string s, vector<string>& ans) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
        }
        if (root->left != nullptr) {
            dfs(root->left, s + "->" + to_string(root->left->val), ans);
        }
        if (root->right != nullptr) {
            dfs(root->right, s + "->" + to_string(root->right->val), ans);
        }
    }
};