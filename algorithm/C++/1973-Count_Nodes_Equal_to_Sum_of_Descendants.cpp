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
    int equalToDescendants(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
    long dfs(TreeNode* root, int& count) {
        if (root == nullptr) {
           return 0;
        }
        long left = dfs(root->left, count);
        long right = dfs(root->right, count);
        if (left + right == root->val) {
            count ++;
        }
        return left + right + root->val;
    }
};
// Time : O(n)
// Space : O(n)