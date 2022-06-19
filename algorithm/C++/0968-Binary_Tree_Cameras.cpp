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
    enum State {
        Have_Camera,
        Need_Camera,
        Covered
    };
    int minCameraCover(TreeNode* root) {
        int count = 0;
        State res = search(root, count);
        if (res == Need_Camera) {
            count++;
        }
        return count;
    }
    State search(TreeNode* root, int& count) {
        if (root==nullptr) {
            return Covered;
        }
        State l = search(root->left, count);
        State r = search(root->right, count);
        
        if (l == Need_Camera || r == Need_Camera) {
            count ++;
            return Have_Camera;
        }
        
        if (l == Have_Camera || r == Have_Camera) { 
            return Covered;
        }
        
        
        return Need_Camera;
    }
};