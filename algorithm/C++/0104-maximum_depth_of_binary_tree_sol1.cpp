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
    void checkTree(TreeNode* node, int depth, int& max_depth){
        if(node == nullptr){
            return;
        }
        max_depth = max(max_depth, depth);

        check_tree(node->left, depth + 1, max_depth);
        check_tree(node->right, depth + 1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int depth = 1;
        int max_depth = 0;
        checkTree(root, depth, max_depth);
        return max_depth;
    }
};
