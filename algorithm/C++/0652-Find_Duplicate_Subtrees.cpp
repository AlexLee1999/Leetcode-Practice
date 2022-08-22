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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> myMap;
        vector<TreeNode*> ans;
        dfs(root, myMap, ans);
        return ans;
    }
    string dfs(TreeNode* root, unordered_map<string, int>& myMap, vector<TreeNode*>& ans) {
        if (root == nullptr) {
            return "null";
        }
        string left = dfs(root->left, myMap, ans);
        string right = dfs(root->right, myMap, ans);
        string cur = to_string(root->val) + '<' + left + '^' + right;
        if (myMap[cur] == 1) {
            ans.push_back(root);
        }
        myMap[cur] ++;
        return cur;
    }
};
// Time : O(n)
// Space : O(logn)