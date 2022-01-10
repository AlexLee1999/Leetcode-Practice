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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int min_depth = INT_MAX;
        dfs(root, 1, min_depth);
        return min_depth;
    }
    void dfs(TreeNode* root, int depth, int& min_depth) {
        if (!root->left && !root->right) {
            min_depth = min(depth, min_depth);
        }
        if (root->left) {
            dfs(root->left, depth+1, min_depth);
        }
        if (root->right) {
            dfs(root->right, depth+1, min_depth);
        }
    }
};