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
    void addNumber(TreeNode* node, int&su, int path_sum){
        if(node->right == nullptr && node->left == nullptr){
            path_sum += node->val;
            su += path_sum;
            return;
        }
        path_sum += node->val;
        path_sum *= 10;
        if(node->right !=nullptr){
            addNumber(node->right, su, path_sum);
        }
        if(node->left != nullptr){
            addNumber(node->left, su, path_sum);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        int s = 0;
        addNumber(root, s, 0);
        return s;
    }
};