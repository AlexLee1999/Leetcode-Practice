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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        dfs(root, freq);
        vector<int> ans;
        int max_val = INT_MIN;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second > max_val) {
                max_val = it->second;
                ans.clear();
            }
            if (it->second == max_val) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
    int dfs(TreeNode* root, unordered_map<int, int>& freq) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, freq);
        int right = dfs(root->right, freq);
        int sum = left + right + root->val;
        freq[sum] ++;
        return sum;
    }
};
// Time : O(n)
// Space : O(logn)