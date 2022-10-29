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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    void dfs(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return;
        }
        dfs(root->right, sum);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        dfs(root->left, sum);
    }
};
// Time : O(N)
// Space : O(H)