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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderindex = n-1;
        unordered_map<int, int> myMap;
        for (int i=0; i<inorder.size(); ++i) {
            myMap[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n-1, postorderindex, myMap);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, int& postorderindex, unordered_map<int, int>& myMap) {
        if (start > end) {
            return nullptr;
        }
        int val = postorder[postorderindex];
        postorderindex--;
        TreeNode* node = new TreeNode(val);
        int pos = myMap[val];
        
        node->right = build(inorder, postorder, pos+1, end, postorderindex, myMap);
        node->left = build(inorder, postorder, start, pos-1, postorderindex, myMap);
        return node;
    }
};
// Time : O(n)
// Space : O(n)