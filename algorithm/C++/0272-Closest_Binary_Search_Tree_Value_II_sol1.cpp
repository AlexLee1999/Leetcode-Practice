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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> myHeap;
        vector<int> ans;
        dfs(root, target, myHeap);
        for (int i=0; i<k; ++i) {
            ans.push_back(myHeap.top().second);
            myHeap.pop();
        }
        return ans;
    }
    void dfs(TreeNode* root, double target, priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>& myHeap) {
        if (root == nullptr) {
            return;
        }
        myHeap.push({abs((double)root->val - target), root->val});
        dfs(root->left, target, myHeap);
        dfs(root->right, target, myHeap);
    }
};
// Time : O(n + klogn)
// Space : O(n)