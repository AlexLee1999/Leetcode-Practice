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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        max_depth(root, max_len);
        return max_len;
    }
    int max_depth(TreeNode* root, int& max_len) {
        if(root == nullptr) {
            return 0;
        }
        int left_max = max_depth(root->left, max_len);
        int right_max = max_depth(root->right, max_len);
        
        max_len = max(max_len, left_max + right_max);
        return 1 + max(left_max, right_max);
    }
};
// Time : O(n)
// Space : O(logn) worst : O(n)