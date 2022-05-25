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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> myQueue;
        unordered_map<int, vector<int>> myMap;
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        myQueue.push({root, 0});
        int max_col = INT_MIN;
        int min_col = INT_MAX;
        while (!myQueue.empty()) {
            TreeNode* node = myQueue.front().first;
            int col = myQueue.front().second;
            myQueue.pop();
            myMap[col].push_back(node->val);
            max_col = max(max_col, col);
            min_col = min(min_col, col);
            if (node->left != nullptr) {
                myQueue.push({node->left, col-1});
            }
            if (node->right != nullptr) {
                myQueue.push({node->right, col+1});
            }
        }
        for (int i=min_col; i<=max_col; ++i) {
            ans.push_back(myMap[i]);
        }
        return ans;
    }
};