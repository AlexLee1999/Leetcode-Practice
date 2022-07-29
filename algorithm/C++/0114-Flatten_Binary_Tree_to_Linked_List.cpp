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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        TreeNode* left_tail = dfs(root->left);
        TreeNode* right_tail = dfs(root->right);
        if (left_tail != nullptr) {
            left_tail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (right_tail == nullptr) {
            return left_tail;
        }
        return right_tail;
        // We flatten the tree and return the tail of the tree
    }
};
// Time : O(n)
// Space : O(n) n recursion stack