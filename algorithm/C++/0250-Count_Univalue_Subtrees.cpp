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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        dfs(root, count);
        return count;
    }
    int dfs(TreeNode* root, int& count) {
        int left = -1001;
        int right = -1001;
        if (root->left != nullptr) {
            left = dfs(root->left, count);
        }
        if (root->right != nullptr) {
            right = dfs(root->right, count);
        }
        if (right == 1001 || left == 1001) {
            return 1001;
        }
        if (right != -1001 && left != -1001) {
            if (right != left || right != root->val || left != root->val) {
                return 1001;
            }
            count ++;
            return root->val;
        }
        if (right == -1001 && left != -1001) {
            if (left != root->val) {
                return 1001;
            }
            count ++;
            return left;
        }
        if (right != -1001 && left == -1001) {
            if (right != root->val) {
                return 1001;
            }
            count ++;
            return right;
        }
        count ++;
        return root->val;
        
    }
};
// Time : O(n)
// Space : O(H)