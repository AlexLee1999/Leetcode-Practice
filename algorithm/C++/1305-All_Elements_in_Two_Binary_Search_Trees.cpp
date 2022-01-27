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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        preorderTraversal(root1, result1);
        vector<int> result2;
        preorderTraversal(root2, result2);
        result1.push_back(INT_MAX);
        result2.push_back(INT_MAX);
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> result;
        while (ptr1 < result1.size()-1 || ptr2 < result2.size()-1) {
            if (result1[ptr1] < result2[ptr2]) {
                result.push_back(result1[ptr1]);
                ptr1 ++;
            } else {
                result.push_back(result2[ptr2]);
                ptr2 ++;
            }
        }
        return result;

    }
    void preorderTraversal(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> myStack;
        TreeNode* curr = root;
        while (!myStack.empty() || curr != nullptr) {
            if (curr) {
                myStack.push(curr);
                curr = curr->left;
            } else{
                TreeNode* top = myStack.top();
                myStack.pop();
                result.push_back(top->val);
                curr = top->right;
            }
        }
    }
};