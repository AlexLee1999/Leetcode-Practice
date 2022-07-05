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
    int checkHeight(TreeNode* node, bool& res) {
        if(node == nullptr){
            return 0;
        }
        int leftHeight = checkHeight(node->left, res);
        int rightHeight = checkHeight(node->right, res);
        if (abs(leftHeight-rightHeight) > 1){
            res = false;
        }
        return 1 + max(leftHeight, rightHeight);
        
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        int h = checkHeight(root, res);
        return res;
    }
};
// Time : O(logn)
// Space : O(1)