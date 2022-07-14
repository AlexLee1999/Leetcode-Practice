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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preindex = 0;
        unordered_map<int, int> myMap;
        for (int i=0; i<inorder.size(); ++i) {
            myMap[inorder[i]] = i;
        }
        return build(preorder, inorder, preindex, 0, n - 1, myMap);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preindex, int start, int end, unordered_map<int, int>& myMap) {
        if (start > end) {
            return nullptr;
        }
        int val = preorder[preindex];
        preindex ++;
        TreeNode* node = new TreeNode(val);
        int inorderindex = myMap[val];
        node->left = build(preorder, inorder, preindex, start, inorderindex - 1, myMap);
        node->right = build(preorder, inorder, preindex, inorderindex + 1, end, myMap);
        return node;
    }
};
// Time : O(n)
// Space : O(n)