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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> myQueue;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        myQueue.push(root);
        while (!myQueue.empty()) {
            int size = myQueue.size();
            int max_val = INT_MIN;
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                max_val = max(max_val, front->val);
                if (front->left != nullptr) {
                    myQueue.push(front->left);
                }
                if (front->right != nullptr) {
                    myQueue.push(front->right);
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};
// Time : O(n)
// Space : O(n)
/* When the tree is balanced, 
the last level will have the maximum width or the maximum number of nodes, 
which will be 2^h (where h is the height of the tree). 
For a balanced tree, h = logn and required size of the queue = O(2^h) = O(2 ^ (log n)) = O(n).
 So space complexity = O(n) */