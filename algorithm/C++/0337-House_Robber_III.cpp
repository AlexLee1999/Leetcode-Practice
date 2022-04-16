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
    unordered_map<TreeNode*, int> myMap;
    int rob(TreeNode* root) {
        return recursive(root);
    }
    int recursive(TreeNode* root){
        if (root == nullptr) {
            return 0;
        }
        if(myMap.find(root) != myMap.end()) {
            return myMap[root];
        }
        int include = 0;
        int exclude = recursive(root->right) + recursive(root->left);
        if (root->left) {
            include += recursive(root->left->left);
            include += recursive(root->left->right);
        }
        if (root->right) {
            include += recursive(root->right->left);
            include += recursive(root->right->right);
        }
        include += root->val;
        myMap[root] = max(include, exclude);
        return max(include, exclude);
    }
};