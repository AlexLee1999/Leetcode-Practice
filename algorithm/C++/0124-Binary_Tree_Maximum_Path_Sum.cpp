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
    int maxPathSum(TreeNode* root) {
        int max_ans = INT_MIN;
        recursive(root, max_ans);
        return max_ans;
    }
    int recursive(TreeNode* root, int& max_ans){
        if (root == nullptr) {
            return 0;
        }
        int left_sum = max(0, recursive(root->left, max_ans));
        int right_sum = max(0, recursive(root->right, max_ans));
        max_ans = max(max_ans, left_sum + right_sum + root->val);
        return root->val + max(right_sum, left_sum);
    }
};