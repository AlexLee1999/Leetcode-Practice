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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
    TreeNode* dfs(TreeNode* root, const int& target) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);
        if (root->val == target && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
};
// Time : O(n)
// Space : O(n)