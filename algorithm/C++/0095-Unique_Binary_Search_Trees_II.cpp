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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
    vector<TreeNode*> generate(int left, int right) {
        if (left > right) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> result;
        for (int i=left; i<=right; ++i) {
            vector<TreeNode*> l = generate(left, i-1);
            vector<TreeNode*> r = generate(i+1, right);
            for (int j=0; j<l.size(); ++j) {
                for (int k=0; k<r.size(); ++k) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l[j];
                    node->right = r[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};