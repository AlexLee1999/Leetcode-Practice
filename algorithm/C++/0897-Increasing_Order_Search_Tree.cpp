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
    TreeNode* increasingBST(TreeNode* root) {
        queue<int> myQueue;
        recursive(root, myQueue);
        TreeNode* cur = new TreeNode(0);
        TreeNode* init_root = cur;
        while(!myQueue.empty()) {
            int val = myQueue.front();
            cur -> right = new TreeNode(val);
            cur = cur -> right;
            myQueue.pop();
        }
        return init_root -> right;
    }
    void recursive(TreeNode* root, queue<int>& q) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            recursive(root->left, q);
        }
        q.push(root->val);
        if (root->right != nullptr) {
            recursive(root->right, q);  
        }
    }
};