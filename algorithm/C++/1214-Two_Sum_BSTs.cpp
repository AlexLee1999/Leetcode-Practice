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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> mySet;
        dfs(root1, mySet);
        
        queue<TreeNode*> myQueue;
        myQueue.push(root2);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            if (mySet.count(target - front->val) != 0) {
                return true;
            }
            if (front->left != nullptr) {
                myQueue.push(front->left);
            }
            if (front->right != nullptr) {
                myQueue.push(front->right);
            }
        }
        return false;
        
    }
    void dfs(TreeNode* root, unordered_set<int>& mySet) {
        if (root == nullptr) {
            return;
        }
        mySet.insert(root->val);
        if (root->left != nullptr) {
            dfs(root->left, mySet);
        }
        if (root->right != nullptr) {
            dfs(root->right, mySet);
        }
    }
};
// Time : O(n)
// Space : O(n)