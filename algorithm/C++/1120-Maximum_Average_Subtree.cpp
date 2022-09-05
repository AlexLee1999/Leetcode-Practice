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
    double maximumAverageSubtree(TreeNode* root) {
        double avg = 0;
        dfs(root, avg);
        return avg;
    }
    pair<int, int> dfs(TreeNode* root, double& avg) {
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left, avg);
        pair<int, int> right = dfs(root->right, avg);
        int total_num = left.first + right.first + 1;
        int total_sum = left.second + right.second + root->val;
        avg = max(avg, (double)total_sum / (double)total_num);
        return {total_num, total_sum};
    }
};
// Time : O(n)
// Space : O(H)