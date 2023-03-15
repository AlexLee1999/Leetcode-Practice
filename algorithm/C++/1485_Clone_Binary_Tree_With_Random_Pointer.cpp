class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> myMap;
        NodeCopy* res = dfs(root, myMap);
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            if (it->first->random != nullptr) { 
                myMap[it->first]->random = myMap[it->first->random];
            }
        }
        return res;
    }
    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& myMap) {
        if (root == nullptr) {
            return nullptr;
        }
        NodeCopy* new_node = new NodeCopy(root->val);
        new_node->left = dfs(root->left, myMap);
        new_node->right = dfs(root->right, myMap);
        myMap[root] = new_node;
        return new_node;
    }
};