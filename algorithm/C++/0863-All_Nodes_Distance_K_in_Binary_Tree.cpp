/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* tmp = myQueue.front();
            visited[tmp] = false;
            myQueue.pop();
            if (tmp->left != nullptr) {
                parent[tmp->left] = tmp;
                myQueue.push(tmp->left);
            } 
            if (tmp->right != nullptr) {
                parent[tmp->right] = tmp;
                myQueue.push(tmp->right);
            }
        }
        int step = 0;
        vector<int> ans;
        myQueue.push(target);
        
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                TreeNode* tmp = myQueue.front();
                visited[tmp] = true;
                myQueue.pop();
                if (step == k) {
                    ans.push_back(tmp->val);
                } else {
                    if (tmp->left != nullptr && !visited[tmp->left]) {
                        myQueue.push(tmp->left);
                    }
                    if (tmp->right != nullptr && !visited[tmp->right]) {
                        myQueue.push(tmp->right);
                    }
                    if (parent[tmp] != nullptr && !visited[parent[tmp]]) {
                        myQueue.push(parent[tmp]);
                    }
                } 
            }
            step ++;
        }
        return ans;
    }
};