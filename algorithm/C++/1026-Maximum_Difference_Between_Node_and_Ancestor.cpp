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
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        dfs(root, diff);
        return diff;
    }
    vector<int> dfs(TreeNode* root, int& diff) { //min, max
        vector<int> left;
        vector<int> right;
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, root->val};
        }
        if (root->left != nullptr) {
            left = dfs(root->left, diff);
        }
        if (root->right != nullptr) {
            right = dfs(root->right, diff);
        }
        int max_num = root->val;
        int min_num = root->val;
        if (!left.empty() && !right.empty()) {
            int min_val = min(left[0], right[0]);
            if (root->val > min_val) {
                diff = max(diff, root->val - min_val);
            }
            int max_val = max(left[1], right[1]);
            if (root->val < max_val) {
                diff = max(diff, max_val - root->val);
            }
            max_num = max(left[1], max(right[1], root->val));
            min_num = min(left[0], min(right[0], root->val));
        } else if (!left.empty()) {
            int min_val = left[0];
            if (root->val > min_val) {
                diff = max(diff, root->val - min_val);
            }
            int max_val = left[1];
            if (root->val < max_val) {
                diff = max(diff, max_val - root->val);
            }
            max_num = max(left[1], root->val);
            min_num = min(left[0], root->val);
        } else if (!right.empty()) {
            int min_val = right[0];
            if (root->val > min_val) {
                diff = max(diff, root->val - min_val);
            }
            int max_val = right[1];
            if (root->val < max_val) {
                diff = max(diff, max_val - root->val);
            }
            max_num = max(right[1], root->val);
            min_num = min(right[0], root->val);
        }
        return {min_num, max_num};
    }
};
// Time : O(n)
// Space : O(H)