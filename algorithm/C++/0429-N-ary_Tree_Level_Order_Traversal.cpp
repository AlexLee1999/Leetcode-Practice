/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<Node*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> tmp;
            for (int i=0; i<size; ++i) {
                Node* front = myQueue.front();
                myQueue.pop();
                tmp.push_back(front->val);
                for (int j=0; j<front->children.size(); ++j) {
                    Node* child = front->children[j];
                    myQueue.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)