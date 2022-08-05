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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* node = LCA(root, p, q);
        queue<TreeNode*> myQueue;
        myQueue.push(node);
        int dis = 0;
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                if (front->val == p || front->val == q) {
                    dis += step;
                }
                if (front->left != nullptr) {
                    myQueue.push(front->left);
                }
                if (front->right != nullptr) {
                    myQueue.push(front->right);
                }
            }
            step ++;
        }
        return dis;
    }
    
    
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == p || root->val == q) {
            return root;
        }
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        if (left == nullptr && right != nullptr) {
            return right;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        return nullptr;
    }
};
// Time : O(n)
// Space : O(n)