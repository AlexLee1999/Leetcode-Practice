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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* t = nullptr;
        dfs(root, parent, t, k);
        queue<TreeNode*> myQueue;
        unordered_set<TreeNode*> visited;
        myQueue.push(t);
        visited.insert(t);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myQueue.pop();
            if (front->left == nullptr && front->right == nullptr) {
                return front->val;
            }
            if (parent[front] != nullptr && !visited.count(parent[front])) {
                myQueue.push(parent[front]);
                visited.insert(parent[front]);
            }
            if (front->left != nullptr && !visited.count(front->left)) {
                myQueue.push(front->left);
                visited.insert(front->left);
            }
            if (front->right != nullptr && !visited.count(front->right)) {
                myQueue.push(front->right);
                visited.insert(front->right);
            }
        }
        return -1;
    }
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode*& t, int k) {
        if (root == nullptr) {
            return;
        }
        if (root->val == k) {
            t = root;
        }
        if (root->left != nullptr) {
            parent[root->left] = root;
            dfs(root->left, parent, t, k);
        }
        if (root->right != nullptr) {
            parent[root->right] = root;
            dfs(root->right, parent, t, k);
        }
    }
};
// Time : O(n)
// Space : O(n)