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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> myMap;
        myMap[0] ++;
        int count = 0;
        preorder(root, targetSum, myMap, count, 0);
        return count;
    }
    void preorder(TreeNode* root, int targetSum, unordered_map<int, int>& myMap, int& count, long long sum) {
        if (root == nullptr){
            return;
        }
        sum += root->val; // Calculate the prefix sum in current path
        count += myMap[sum - targetSum];
        myMap[sum] ++;
        preorder(root->left, targetSum, myMap, count, sum);
        preorder(root->right, targetSum, myMap, count, sum);
        myMap[sum] --; // restore the origin prefix sum
    }
};
// Time : O(n)
// Space : O(n)