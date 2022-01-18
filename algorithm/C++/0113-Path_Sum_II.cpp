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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }
        vector<int> current_result = {root->val};
        int current = root->val;
        dfs(root, targetSum, current, current_result, results);
        return results;
        
    }
    void dfs(TreeNode* node, const int& target, int current, vector<int>& current_result, vector<vector<int>>& results) {
        if (isLeaf(node) && current == target) {
            results.push_back(current_result);
            return;
        } 
        if (isLeaf(node) && current != target) {
            return;
        }
        if (node->left != nullptr) {
            current_result.push_back(node->left->val);
            dfs(node->left, target, current + node->left->val, current_result, results);
            current_result.pop_back();
        }
        if (node->right != nullptr) {
            current_result.push_back(node->right->val);
            dfs(node->right, target, current + node->right->val, current_result, results);
            current_result.pop_back();
        }
        
    }
    bool isLeaf(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        } else {
            return false;
        }
    }
};