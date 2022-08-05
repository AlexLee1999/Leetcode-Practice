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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> myMap;
        return recursive(root, myMap);
    }
    int recursive(TreeNode* root, unordered_map<TreeNode*, int>& myMap){
        if (root == nullptr) {
            return 0;
        }
        if(myMap.find(root) != myMap.end()) {
            return myMap[root];
        }
        int include = 0;
        int exclude = recursive(root->right, myMap) + recursive(root->left, myMap);
        if (root->left) {
            include += recursive(root->left->left, myMap);
            include += recursive(root->left->right, myMap);
        }
        if (root->right) {
            include += recursive(root->right->left, myMap);
            include += recursive(root->right->right, myMap);
        }
        include += root->val;
        myMap[root] = max(include, exclude);
        return max(include, exclude);
    }
};
// Time : O(n)
// Space : O(H)