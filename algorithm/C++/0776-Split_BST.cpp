class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> arr(2, nullptr);
        if (root == nullptr) {
            return arr;
        }
        if (root->val > target) {
            arr[1] = root;
            vector<TreeNode*> tmp = splitBST(root->left, target);
            root->left = tmp[1];
            arr[0] = tmp[0];
        } else {
            arr[0] = root;
            vector<TreeNode*> tmp = splitBST(root->right, target);
            root->right = tmp[0];
            arr[1] = tmp[1];
        }
        return arr;
    }
};