/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int hasfound = 0;
        TreeNode* res = dfs(root, p, q, hasfound);
        if (hasfound == 2) {
            return res;
        }
        return nullptr;
        
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, int& hasfound) {
        if (root == nullptr) {
            return root;
        }
        
        TreeNode* left = dfs(root->left, p, q, hasfound);
        TreeNode* right = dfs(root->right, p, q, hasfound);
        if (root == p || root == q) {
            hasfound ++;
            return root;
        }
        if (left == nullptr && right != nullptr) {
            return right;
        } else if (left != nullptr && right == nullptr) {
            return left;
        } else if (left != nullptr && right != nullptr) {
            return root;
        } else {
            return nullptr;
        }
    }
};
// Time : O(n)
// Space : O(n)