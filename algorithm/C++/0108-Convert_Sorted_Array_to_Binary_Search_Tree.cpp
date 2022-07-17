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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(0, nums.size()-1, nums);
    }
    TreeNode* recursive(int left, int right, const vector<int>& nums) {
        if (left > right) {
            return nullptr;
        }
        int mid = (right - left) / 2 + left;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = recursive(left, mid-1, nums);
        node->right = recursive(mid + 1, right, nums);
        return node;
    }
};
// Time : O(N)
// Space : O(logN)