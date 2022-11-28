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
    bool valid(TreeNode* node, TreeNode* max, TreeNode* min){
        if(node == nullptr){
            return true;
        }
        if(((max != nullptr) && node->val >= max->val) || (min != nullptr) && (node->val <= min->val)){
            return false;
        }
        return valid(node->left, node, min)&&valid(node->right, max, node);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }
};
// Time : O(H)
// Space : O(H)