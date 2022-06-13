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
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        dfs(root, arr);
        int min_dis = INT_MAX;
        for (int i=1; i<arr.size(); ++i) {
            min_dis = min(min_dis, arr[i]-arr[i-1]);
        }
        return min_dis;
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
// Time : O(n)
// Space : O(n)