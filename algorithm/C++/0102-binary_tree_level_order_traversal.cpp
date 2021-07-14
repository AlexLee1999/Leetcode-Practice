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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        while (!que.empty()) {
            vector<int> res_tmp;
            int n = que.size();
            for (int i=0; i<n; ++i) {
                tmp = que.front();
                res_tmp.push_back(tmp->val);
                if (tmp->left != nullptr) {
                    que.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    que.push(tmp->right);
                }
                que.pop();
            }
            res.push_back(res_tmp);
        }
        return res;
    }
};
