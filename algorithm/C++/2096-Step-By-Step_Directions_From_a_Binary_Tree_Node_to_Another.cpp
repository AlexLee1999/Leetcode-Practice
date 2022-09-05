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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* parent = LCA(root, startValue, destValue);
        string path_s = "";
        string path_d = "";
        dfs(parent, startValue, path_s);
        dfs(parent, destValue, path_d);
        for (int i=0; i<path_s.size(); ++i) {
            path_s[i] = 'U';
        }
        return path_s + path_d;
    }
    TreeNode* LCA(TreeNode* root, int startValue, int destValue) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == startValue || root->val == destValue) {
            return root;
        }
        TreeNode* left = LCA(root->left, startValue, destValue);
        TreeNode* right = LCA(root->right, startValue, destValue);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        if (left == nullptr && right != nullptr) {
            return right;
        }
        return nullptr;
    }
    bool dfs(TreeNode* root, int val, string& path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == val) {
            return true;
        }
        path.push_back('L');
        if (dfs(root->left, val, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (dfs(root->right, val, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};
// Time : O(n)
// Space : O(H)