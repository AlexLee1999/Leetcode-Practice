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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int sum;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            sum = 0;
            for (int i=0; i<size; ++i) {
                TreeNode* node = myQueue.front();
                sum += node->val;
                myQueue.pop();
                if (node->left != nullptr) {
                    myQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    myQueue.push(node->right);
                }
            }
        }
        return sum;
    }
};