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
        int max_len = 0;
        dfs(root, max_len);
        return max_len;
    }
    vector<int> dfs(TreeNode* root, int& max_len) {
        if (root == nullptr) {
            return {0, 0};
        }
        int increasing = 1;
        int decreasing = 1;
        if (root->left != nullptr) {
            vector<int> left = dfs(root->left, max_len);
            if (root->left->val + 1 == root->val) {
                decreasing = max(decreasing, left[0] + 1);
            } else if (root->left->val == root->val + 1) {
                increasing = max(increasing, left[1] + 1);
            }
        }
        if (root->right != nullptr) {
            vector<int> right = dfs(root->right, max_len);
            if (root->right->val + 1 == root->val) {
                decreasing = max(decreasing, right[0] + 1);
            } else if (root->right->val == root->val + 1) {
                increasing = max(increasing, right[1] + 1);
            }
        }
        max_len = max(max_len, increasing + decreasing - 1);
        return {decreasing, increasing};
    }
};
// Time : O(n)
// Space : O(logn)