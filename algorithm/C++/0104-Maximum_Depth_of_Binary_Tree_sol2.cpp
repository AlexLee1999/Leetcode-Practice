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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int height = 0;
        TreeNode* tmp;
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                tmp = que.front();
                if (tmp->left != nullptr) {
                    que.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    que.push(tmp->right);
                }
                que.pop();
            }
            height++;
        }
        return height;
    }
};
// Time : O(n)
// Space : O(n)
