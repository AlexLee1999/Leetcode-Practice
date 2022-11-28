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
    bool is_true(TreeNode* a, TreeNode* b){
        if(a == nullptr && b==nullptr){
            return true;
        }
        if((a == nullptr && b!=nullptr) ||(a != nullptr && b==nullptr) || (a->val != b->val)){
            return false;
        }
        return is_true(a->left, b->left)&&is_true(a->right, b->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return is_true(p, q);
    }
};
// Time : O(n)
// Space : O(H)