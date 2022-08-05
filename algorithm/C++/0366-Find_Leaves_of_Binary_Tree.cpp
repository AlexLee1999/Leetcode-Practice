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
    vector<vector<int>> findLeaves(TreeNode* root) {
        stack<TreeNode*> myStack;
        unordered_map<TreeNode*, TreeNode*> myMap;
        unordered_map<TreeNode*, int> indegree;
        vector<vector<int>> ans;
        myStack.push(root);
        while (!myStack.empty()) {
            TreeNode* top = myStack.top();
            myStack.pop();
            indegree[top] = 0;
            if (top->left != nullptr) {
                myStack.push(top->left);
                myMap[top->left] = top;
                indegree[top] ++;
            }
            if (top->right != nullptr) {
                myStack.push(top->right);
                myMap[top->right] = top;
                indegree[top] ++;
            }
        }
        queue<TreeNode*> myQueue;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0) {
                myQueue.push(it->first);
            }
        }
        while (!myQueue.empty()) {
            vector<int> tmp;
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                TreeNode* front = myQueue.front();
                myQueue.pop();
                tmp.push_back(front->val);
                if (myMap[front] != nullptr) {
                    indegree[myMap[front]] --;
                    if (indegree[myMap[front]] == 0) {
                        myQueue.push(myMap[front]);
                    }
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};