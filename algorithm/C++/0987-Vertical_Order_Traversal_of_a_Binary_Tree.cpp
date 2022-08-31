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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> myMap;
        dfs(root, myMap, 0, 0);
        vector<vector<int>> ans;
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            vector<int> tmp;
            for (auto it_2 = it->second.begin(); it_2 != it->second.end(); ++it_2) {
                sort(it_2->second.begin(), it_2->second.end());
                tmp.insert(tmp.end(), it_2->second.begin(), it_2->second.end());
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    void dfs(TreeNode* root, map<int, map<int, vector<int>>>& myMap, int cur, int height) {
        myMap[cur][height].push_back(root->val);
        if (root->left != nullptr) {
            dfs(root->left, myMap, cur - 1, height + 1);
        }
        if (root->right != nullptr) {
            dfs(root->right, myMap, cur + 1, height + 1);
        }
    }
};
// Time : O(nlogn)
// Space : O(n)