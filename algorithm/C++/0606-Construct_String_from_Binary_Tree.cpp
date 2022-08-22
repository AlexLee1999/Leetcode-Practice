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
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
    string dfs(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string left = dfs(root->left);
        string right = dfs(root->right);
        if (left == "" && right == "") {
            return to_string(root->val);
        }
        if (left != "" && right == "") {
            return to_string(root->val) + '(' + left + ')';
        }
        if (left == "" && right != "") {
            return to_string(root->val) + "()" +'(' + right + ')';
        }
        return to_string(root->val) + '(' + left + ')' + '(' + right + ')';
    }
};
// Time : O(n)
// Space : O(logn)
