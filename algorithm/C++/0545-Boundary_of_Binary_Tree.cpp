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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val};
        }
        vector<int> ans;
        vector<int> leafs;
        findLeaf(root, leafs);
        vector<int> left = leftBound(root->left);
        vector<int> right = rightBound(root->right);
        ans.push_back(root->val);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leafs.begin(), leafs.end());
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    vector<int> leftBound(TreeNode* root) {
        vector<int> boundary;
        if (root == nullptr) { // If the left node is empty, return {}
            return {};
        }
        while (root->left != nullptr || root->right != nullptr) { // not a leaf
            boundary.push_back(root->val);
            if (root->left != nullptr) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return boundary;
    }
    vector<int> rightBound(TreeNode* root) {
        vector<int> boundary;
        if (root == nullptr) { // If the right node is empty, return {}
            return {};
        }
        while (root->left != nullptr || root->right != nullptr) { // not a leaf
            boundary.push_back(root->val);
            if (root->right != nullptr) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        reverse(boundary.begin(), boundary.end());
        return boundary;
    }
    void findLeaf(TreeNode* root, vector<int>& leafs) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leafs.push_back(root->val);
            return;
        }
        findLeaf(root->left, leafs);
        findLeaf(root->right, leafs);
    }
};
// Time : O(n)
// Space : O(n)