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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        if (depth == 1) {
            TreeNode* dummy = new TreeNode(val);
            dummy->left = root;
            return dummy;
        }
        int cur_depth = 1;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                if (cur_depth == depth - 1) {
                    TreeNode* left = front->left;
                    TreeNode* right = front->right;
                    front->left = new TreeNode(val);
                    front->right = new TreeNode(val);
                    front->left->left = left;
                    front->right->right = right;
                }
                if (front->left != nullptr) {
                    myQueue.push(front->left);
                }
                if (front->right != nullptr) {
                    myQueue.push(front->right);
                }
            }
            
           cur_depth ++; 
            if (cur_depth >= depth) {
                return root;
            }
        }
        return nullptr;
    }
};
// Time : O(n)
// Space : O(n)