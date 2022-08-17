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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        TreeNode* ans_root = nullptr;
        dfs(root, ans_root);
        return ans_root;
    }
    TreeNode* dfs(TreeNode* root, TreeNode*& ans_root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        TreeNode* left = dfs(root->left, ans_root);
        TreeNode* right = dfs(root->right, ans_root);
        if (left != nullptr) {
            left->left = right;
            left->right = root;
            root->left = nullptr;
            root->right = nullptr;
            if (ans_root == nullptr) {
                ans_root = left;
            }
        }
        return root;
    }
};
// Time : O(n)
// Space : O(logn)