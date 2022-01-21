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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> current_result;
            for (int i=0; i<size; ++i) {
                TreeNode* front = Q.front();
                Q.pop();
                current_result.push_back(front->val);
                if (front->left != nullptr) {
                    Q.push(front->left);
                }
                if (front->right != nullptr) {
                    Q.push(front->right);
                } 
            }
            if ((depth & 1) == 1) {
                reverse(current_result.begin(), current_result.end());
            }
            results.push_back(current_result);
            depth ++;
        }
        return results;
    }
};