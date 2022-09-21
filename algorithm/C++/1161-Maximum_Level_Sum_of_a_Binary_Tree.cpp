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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int ans = -1;
        int max_sum = INT_MIN;
        int level = 1;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            int sum = 0;
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                sum += front->val;
                if (front->left != nullptr) {
                    myQueue.push(front->left);
                }
                if (front->right != nullptr) {
                    myQueue.push(front->right);
                }
            }
            if (max_sum < sum) {
                max_sum = sum;
                ans = level;
            }
            level ++;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)