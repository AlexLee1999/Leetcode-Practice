class Solution {
public:
    void checkPathSum(TreeNode* node, const int& targetSum, int value, bool& hasSum) {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val + value == targetSum) {
                hasSum = true;
            }
        }
        if (node->left != nullptr) {
            checkPathSum(node->left, targetSum, value + node->val, hasSum);
        }
        if (node->right != nullptr) {
            checkPathSum(node->right, targetSum, value + node->val, hasSum);
        }

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool hasSum = false;
        if (root == nullptr) {
            return false;
        }
        checkPathSum(root, targetSum, 0, hasSum);
        return hasSum;
    }
};
