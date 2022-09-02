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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pre;
        stack<TreeNode*> suc;
        vector<int> ans;
        while (root != nullptr) {
            if (root->val > target) {
                suc.push(root);
                root = root->left;
            } else {
                pre.push(root);
                root = root->right;
            }
        }
        while (k > 0) {
            if ((suc.empty()) || !pre.empty() && target - pre.top()->val < suc.top()->val - target) {
                ans.push_back(pre.top()->val);
                TreeNode* tmp = pre.top();
                pre.pop();
                if (tmp->left != nullptr) {
                    pre.push(tmp->left);
                    while (pre.top()->right != nullptr) {
                        pre.push(pre.top()->right);
                    }
                } 
            } else {
                ans.push_back(suc.top()->val);
                TreeNode* tmp = suc.top();
                suc.pop();
                if (tmp->right != nullptr) {
                    suc.push(tmp->right);
                    while (suc.top()->left != nullptr) {
                        suc.push(suc.top()->left);
                    }
                } 
            }
            k --;
        }
        return ans;
    }
};
// Time : O(klogn)
// Space : O(logn)