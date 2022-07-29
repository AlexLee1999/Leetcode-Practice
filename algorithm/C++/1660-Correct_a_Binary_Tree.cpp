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
enum Colors {WHITE, GRAY, BLACK};
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, Colors> visited;
        return dfs(root, visited);
    }
    TreeNode* dfs(TreeNode* root, unordered_map<TreeNode*, Colors>& visited) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->right != nullptr && visited[root->right] != WHITE) {
            return nullptr;
        }
        
        visited[root] = GRAY;
        root->right = dfs(root->right, visited);
        root->left = dfs(root->left, visited);
        visited[root] = BLACK;
        return root;
    }
};
// Time : O(n)
// Space : O(n)