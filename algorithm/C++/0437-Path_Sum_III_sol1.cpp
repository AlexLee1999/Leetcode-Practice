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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfs(root, targetSum, count);
        return count;
    }
    void dfs(TreeNode* root, int targetSum, int& count) {
        if (root == nullptr) {
            return;
        }
        subPath(root, 0, targetSum, count);
        dfs(root->left, targetSum, count);
        dfs(root->right, targetSum, count);
    }
    void subPath(TreeNode* root, long long sum, int target, int& count) {
        if (root == nullptr) {
            return;
        }
        if (sum + root->val == target) {
            count++;
        }
        subPath(root->left, sum + root->val, target, count);
        subPath(root->right, sum + root->val, target, count);
    }
};