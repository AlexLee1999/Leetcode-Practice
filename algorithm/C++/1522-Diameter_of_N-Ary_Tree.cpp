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
    int diameter(Node* root) {
        int max_len = 0;
        dfs(root, max_len);
        return max_len;
    }
    int dfs(Node* root, int& max_len) {
        if (root == nullptr) {
            return 0;
        }
        int first = 0;
        int second = 0;
        for (int i=0; i<root->children.size(); ++i) {
            int depth = dfs(root->children[i], max_len);
            if (depth > first) {
                second = first;
                first = depth;
            } else if (depth <= first && depth > second) {
                second = depth;
            }
        }
        max_len = max(max_len, second + first);
        return first + 1;
    }
};
// Time : O(n)
// Space : O(H)