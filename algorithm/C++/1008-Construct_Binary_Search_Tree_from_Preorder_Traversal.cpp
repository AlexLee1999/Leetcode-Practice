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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
    TreeNode* dfs(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int i = start;
        for (i=start; i<=end; ++i) {
            if (preorder[i] > preorder[start]) {
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[start]);
        root->left = dfs(preorder, start + 1, i - 1);
        root->right = dfs(preorder, i, end);
        return root;
    }
};
// Time : O(n)
// Space : O(H)