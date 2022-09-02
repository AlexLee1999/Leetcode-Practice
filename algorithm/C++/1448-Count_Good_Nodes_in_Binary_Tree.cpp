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
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, count, INT_MIN);
        return count;
    }
    void dfs(TreeNode* root, int& count, int cur_max) {
        if (root == nullptr) {
            return;
        }
        if (root->val >= cur_max) {
            count ++;
        }
        cur_max = max(cur_max, root->val);
        dfs(root->left, count, cur_max);
        dfs(root->right, count, cur_max);
    }
};
// Time : O(n)
// Space : O(n)