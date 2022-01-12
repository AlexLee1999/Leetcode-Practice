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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root != nullptr){
            dfs(root, val);
            return root; 
        } else {
            TreeNode* new_node = new TreeNode(val);
            return new_node;
        }
        
        
    }
    void dfs(TreeNode* root, int value) {
        TreeNode* new_node = new TreeNode(value);
        if (root->val < value) {
            if (!root->right) {
                root->right = new_node;
                return;
            }
            dfs(root->right, value);
        }
        if (root->val > value) {
            if (!root->left) {
                root->left = new_node;
                return;
            }
            dfs(root->left, value);
        }
    }
};