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
    int closestValue(TreeNode* root, double target) {
        double closest = root->val;
        while (root != nullptr) {
            if (fabs(root->val - target) < fabs(closest - target)) {
                closest = root->val;
            }
            if (root->val < target) {
               root = root->right;
            } else if (root->val > target) {
               root = root->left;
            } else {
                return root->val;
            }
        }
        return closest;
    }
};