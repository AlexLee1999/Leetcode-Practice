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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int max_val = *max_element(nums.begin() + left, nums.begin() + right + 1);
        int n = nums.size();
        int pos = 0;
        for (int i=left; i<=right; ++i) {
            if (nums[i] == max_val) {
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = buildTree(nums, left, pos - 1);
        root->right = buildTree(nums, pos + 1, right);
        return root;
    }
};
// Time : O(nlogn)
// Space : O(H)