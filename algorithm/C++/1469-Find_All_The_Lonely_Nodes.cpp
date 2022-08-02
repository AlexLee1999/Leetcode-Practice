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
    vector<int> getLonelyNodes(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        vector<int> ans;
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            if (front->left != nullptr) {
                if (front->right == nullptr) {
                    ans.push_back(front->left->val);
                }
                myQueue.push(front->left);
            }
            if (front->right != nullptr) {
                if (front->left == nullptr) {
                    ans.push_back(front->right->val);
                }
                myQueue.push(front->right);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)