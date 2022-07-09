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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int step = 0;
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                if (front->left == nullptr && front->right == nullptr) {
                    return step + 1;
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
        return -1;
    }
};
// Time : O(n)
// Space : O(n)