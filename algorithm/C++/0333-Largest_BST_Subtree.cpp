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
    int largestBSTSubtree(TreeNode* root) {
        int max_num = 0;
        dfs(root, max_num);
        return max_num;
    }
    vector<int> dfs(TreeNode* root, int& max_num) {
        if (root == nullptr) {
            return {0, INT_MAX, INT_MIN}; // num, min_val, max_val
        }
        vector<int> left = dfs(root->left, max_num);
        vector<int> right = dfs(root->right, max_num);
        if (root->left != nullptr && left[2] >= root->val) {
            return {-1, min(left[1], root->val), max(right[2], root->val)};
        }
        if (root->right != nullptr && right[1] <= root->val) {
            return {-1, min(left[1], root->val), max(right[2], root->val)};
        }
        if (left[0] != -1 && right[0] != -1) {
            max_num = max(max_num, left[0] + right[0] + 1);
            return {left[0] + right[0] + 1, min(left[1], root->val), max(right[2], root->val)};
        }
        return {-1, min(left[1], root->val), max(right[2], root->val)};
    }
};
// Time : O(n)
// Space : O(n)