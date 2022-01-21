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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }
        queue<TreeNode*> Q;
        Q.push(root);
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
            results.push_back(current_result);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};