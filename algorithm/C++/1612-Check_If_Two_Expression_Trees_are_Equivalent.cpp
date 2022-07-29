/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> table(26, 0);
        dfs(root1, table, true);
        dfs(root2, table, false);
        for (int i=0; i<26; ++i) {
            if (table[i] != 0) {
                return false;
            }
        }
        return true;
        
    }
    void dfs(Node* root, vector<int>& table, bool isFirst) {
        if (root->left == nullptr && root->right == nullptr) {
            if (isFirst) {
                table[root->val - 'a'] ++;
            } else {
                table[root->val - 'a'] --;
            }
            return;
        }
        dfs(root->left, table, isFirst);
        dfs(root->right, table, isFirst);
    }
};
// Time : O(n + m)
// Space : O(1)