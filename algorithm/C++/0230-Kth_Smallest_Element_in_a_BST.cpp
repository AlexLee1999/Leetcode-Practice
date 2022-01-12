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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while (tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->left;
        }
        while (k > 1) {
            tmp = s.top();
            s.pop();
            if (tmp->right != nullptr) {
                tmp = tmp->right;
                while (tmp != nullptr) {
                    s.push(tmp);
                    tmp = tmp->left;
                }
            }
            k--;
        }
        return s.top()->val;
    }
};
