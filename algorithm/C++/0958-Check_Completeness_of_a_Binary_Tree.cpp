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
    bool isCompleteTree(TreeNode* root) {
        int n = countSize(root);
        return dfs(root, 0, n);
        
        
    }
    int countSize(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return countSize(root->left) + 1 + countSize(root->right);
    }
    bool dfs(TreeNode* root, int idx, int n) {
        if (root == nullptr) {
            return true;
        }
        if (idx >= n) {
            return false;
        }
        return dfs(root->left, 2 * idx + 1, n) && dfs(root->right, 2 * idx + 2, n);
    }
};
// Time : O(n)
// Space : O(1)