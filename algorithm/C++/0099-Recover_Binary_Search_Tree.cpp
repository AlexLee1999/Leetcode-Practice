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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        if (root == nullptr) {
            return;
        }
        TreeNode* node = root;
        dfs(root, inorder);
        bool found = false;
        TreeNode* first;
        TreeNode* second;
        for (int i=0; i<inorder.size() - 1; ++i) {
            if (inorder[i]->val > inorder[i + 1]->val && !found) {
                first = inorder[i];
                second = inorder[i + 1];
                found = true;
            } else if (inorder[i]->val > inorder[i + 1]->val && found) {
                second = inorder[i + 1];
            }
        }
        swap(first, second);
    }
    void dfs(TreeNode* root, vector<TreeNode*>& inorder) {
        if (root != nullptr) {
            dfs(root->left, inorder);
            inorder.push_back(root);
            dfs(root->right, inorder);
        }
    }
    void swap(TreeNode*& a, TreeNode*& b) {
        int tmp = b->val;
        b->val = a->val;
        a->val = tmp;
    }
};