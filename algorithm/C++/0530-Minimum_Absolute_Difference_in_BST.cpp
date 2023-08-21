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
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        dfs(root, arr);
        int diff = INT_MAX;
        for (int i=0; i<arr.size() - 1; ++i) {
            diff = min(diff, arr[i + 1] - arr[i]);
        }
        return diff;
    }
    void dfs(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
};