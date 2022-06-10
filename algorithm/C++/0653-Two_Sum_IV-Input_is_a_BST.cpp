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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> myQueue;
        unordered_set<int> mySet;
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            if (mySet.count(k - front->val) != 0) {
                return true;
            }
            mySet.insert(front->val);
            if (front->left != nullptr) {
                myQueue.push(front->left);
            }
            if (front->right != nullptr) {
                myQueue.push(front->right);
            }
        }
        return false;
    }
};
// Time : O(N)
// Space : O(N)