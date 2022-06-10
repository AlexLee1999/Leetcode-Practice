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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        int count = 0;
        unordered_set<TreeNode*> mySet(nodes.begin(), nodes.end());
        TreeNode* res = dfs(root, mySet, count);
        if (count == nodes.size()) {
            return res;
        }
        return nullptr;
    }
    TreeNode* dfs(TreeNode* root, unordered_set<TreeNode*>& mySet, int& count) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* left = dfs(root->left, mySet, count);
        TreeNode* right = dfs(root->right, mySet, count);
        
        if (mySet.count(root)) {
            count ++;
            return root;
        }
        
        if (left == nullptr && right != nullptr) {
            return right;
        } else if (left != nullptr && right == nullptr) {
            return left;
        } else if (left != nullptr && right != nullptr) {
            return root;
        } else {
            return nullptr;
        }
    }
};
// Time : O(n)
// Space : O(n)