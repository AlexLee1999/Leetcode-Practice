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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int ans = 0;
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            
            if (front->left != nullptr) {
                myQueue.push(front->left);
                if (isLeaf(front->left)) {
                    ans += front->left->val;
                }
                
            }
            if (front->right != nullptr) {
                myQueue.push(front->right);
            }
        }
        return ans;
    }
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
// Time : O(n)
// Space : O(n)