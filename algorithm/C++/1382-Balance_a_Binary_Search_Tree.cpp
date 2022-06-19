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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);
        return build(inorder, 0, inorder.size() - 1);
        
    }
    void dfs(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
    TreeNode* build (vector<int>& arr, int start, int end) {
        if (end < start) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr, start, mid-1);
        root->right = build(arr, mid + 1, end);
        return root;
    }
};
// Time : O(n)
// Space : O(n)